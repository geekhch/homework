#coding:utf-8

from wordcloud import WordCloud
import matplotlib.pyplot as plt
import jieba
import jieba.posseg as pseg
from sqlSet import Mysql

def create_word_cloud(filename):
    text= open(filename).read()
    # 结巴分词
    wordlist = jieba.cut(text) #, cut_all=False
    wl = " ".join(wordlist)
    return wl

def get_ciyun(wl):
    # 设置词云
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


def test_sql():
    client = Mysql()
    word = "y"
    sql = "select word from words where word = '%s'" % word
    set = client.querry(sql)
    if set:
        print('true')


def save_flag():
    client = Mysql()
    sql = "select word from words"
    words = client.querry(sql)

    for word in words:
        c_word = word['word']
        t_word = pseg.cut(c_word)
        for w in t_word:
            print(c_word, w.word,w.flag)

def write():
    '''按词频生成词云'''
    client = Mysql()
    ws = client.querry("select * from words where flag='n'")
    str = {}
    for word in ws:
        # for i in range(word['count']):
        if word['flag']=='n' or len(word['word']) > 1:
            str[word['word']] = word['count']
    print(str)
    get_ciyun(str)

write()