#coding:utf-8

from wordcloud import WordCloud
import matplotlib.pyplot as plt
import jieba
import jieba.posseg as pseg
from sqlSet import Mysql

def create_word_cloud(filename):
    '''结巴分词'''
    text= open(filename).read()
    wordlist = jieba.cut(text) #, cut_all=False
    wl = " ".join(wordlist)
    return wl

def get_ciyun(wl):
    '''设置词云'''
    wc = WordCloud(
        background_color="white",  # 设置背景颜色
        max_words=200,  # 设置最大显示的词云数
        font_path='C:\\Windows\\Fonts\\STXINGKA.TTF',  # 这种字体都在电脑字体中，一般路径
        height= 1200,
        width= 1600,
        max_font_size=150,
        random_state=30
    )
    myword = wc.generate_from_frequencies(wl)  # 生成词云
    wc.to_file('py_book.png')  # 把词云保存下


def save_to_sql():
    '''将爬取的文本保存到数据库'''
    client = Mysql()
    with open('scuinfo.txt', 'r') as f:
        for i in range(5429):
            line = (f.__next__()[:-1]).split('], [')
            sql = u"INSERT IGNORE INTO scuinfo(content, user, comment_num, good_num) VALUES('{0}','{1}',{2},{3})".format(line[0],line[1],line[2],line[3])
            try:
                client.update(sql)
                print(i)
            except:
                print("error", i)
    client.close()


def update_sql_words():
    '''将爬取的帖子分词，并保存到数据库'''
    client = Mysql()
    sql = 'select content from scuinfo'
    contents = client.querry(sql)
    i = 1
    for item in contents:
        text = item['content']
        words = pseg.cut(text)
        # wl = " ".join(words).split(' ')
        i+=1
        print(i)
        # if(i == 30):
        #     break
        for word in words:
            sql2 = "select * from words where word = '%s'" % word.word
            set2 = client.querry(sql2)
            if set2:
                client.update("update words set count = {0} where id = {1}".format(set2[0]['count']+1, set2[0]['id']))
            else:
                client.update("insert into words(word, flag) values('{0}', '{1}')".format(word.word, word.flag))



def save_flag():
    '''给词汇添加词性'''
    client = Mysql()
    sql = "select word from words"
    words = client.querry(sql)

    for word in words:
        c_word = word['word']
        t_word = pseg.cut(c_word)
        for w in t_word:
            print(c_word, w.word,w.flag)



def write():
    '''按爬取数据分词后，选取有意义的词性词频生成词云图'''
    client = Mysql()
    ws = client.querry("select * from words where flag='n'")
    str = {}
    for word in ws:
        # for i in range(word['count']):
        if word['flag']=='n' or len(word['word']) > 1:
            str[word['word']] = word['count']
    print(str)
    get_ciyun(str)


def setSentment():
    '''使用第三方语料库给数据库中词汇增加情感评分'''
    client = Mysql()
    sql = "select * from words"
    words_sql = client.querry(sql)
    with open('src/sentiment.txt', 'r', encoding='utf-8') as f:
        item = f.__next__()
        list_all = []
        while(item != ''):
            item_1 = item[:-1].split(' ')
            list_all.append(item_1)
            try:
                item = f.__next__()
            except:
                break
    words_dict = dict(list_all)
    for i in words_sql:
        for key in words_dict:
            if i['word'] == key:
                client.update('update words set sentment = {0} where id = {1}'.format(words_dict[key], i['id']))


def score():
    '''帖子情感评分'''
    client = Mysql()
    sql1 = "select word, sentment from info_words where sentment is not null"
    sql2 = "select * from info_contents"
    info_contents = client.querry(sql2)
    info_words = client.querry(sql1)

    for i in info_contents:
        score1 = 0
        wordlist = jieba.cut(i['content'])  # , cut_all=False
        wl = (" ".join(wordlist)).split(" ")
        for j in wl:
            for k in info_words:
                if k['word'] == j:
                    # print(score1,k['sentment'])
                    score1 += k['sentment']
                    break
        i['score'] = score1
    for i in info_contents:
        try:
            client.update("update info_contents set score = {0} where id = {1}".format(i['score'], i['id']))
        except:
            print('eee')

score()