#coding:utf-8

from wordcloud import WordCloud
import matplotlib.pyplot as plt
import jieba
import jieba.posseg as pseg

#生成词云
def create_word_cloud(filename):
    text= open("{0}.txt".format(filename),encoding='utf-8').read()
    # 结巴分词
    wordlist = pseg.cut(text) #, cut_all=False
    for i in wordlist:
        print(i.word,i.flag)
    # wl = " ".join(wordlist)
    # print(wl)

    # # 设置词云
    # wc = WordCloud(
    #     # 设置背景颜色
    #    background_color="white",
    #      # 设置最大显示的词云数
    #    max_words=150,
    #      # 这种字体都在电脑字体中，一般路径
    #    font_path='C:\\Windows\\Fonts\\STXINGKA.TTF',
    #    height= 1200,
    #    width= 1600,
    #     # 设置字体最大值
    #    max_font_size=100,
    #  # 设置有多少种随机生成状态，即有多少种配色方案
    #    random_state=30,
    # )

    # myword = wc.generate(wl)  # 生成词云
    # # 展示词云图
    # plt.imshow(myword)
    # plt.axis("off")
    # plt.show()
    # wc.to_file('py_book.png')  # 把词云保存下

if __name__ == '__main__':
    create_word_cloud('hch\\qq_word')