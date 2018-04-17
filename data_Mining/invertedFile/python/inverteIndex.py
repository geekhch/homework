#coding:utf-8
import os, sys

'''获取文件列表'''
def getDocPath(path):
    documents = os.listdir(path)
    fileList = []
    print("文件列表：\n")
    for doc in documents:
        fileList.append(os.path.join(path,doc))
        index = len(fileList)-1 #获取当前文件路径下标
        print(index, fileList[index])
    return fileList

'''获取每个文件的单词数统计'''
def getWordsList():
    wordsList=[] #使用列表保存每个文件的单词
    fileList = getDocPath("/home/hch/homework/dataMining/invertedFile/documents")
    print("\n\n文件内容：\n")
    for doc in fileList:
        cur_file = open(doc)
        strLine = cur_file.readline()
        print(strLine)
        cur_Doc_Words = {}

        while(strLine != ''):
            cur_words = strLine.split(' ')
            for word in cur_words:
                if cur_Doc_Words.get(word) != None:
                    cur_Doc_Words[word] += 1
                else:
                    cur_Doc_Words[word] = 1
            strLine = cur_file.readline() #read next line

        wordsList.append(cur_Doc_Words)
    # for item in wordList:
    #     print(item)
    return wordsList

'''倒排索引'''
wordList = getWordsList()
print("\n\n正序索引：\n")
for item in wordList:
    print(item)
invert_index = {}

for doc in range(len(wordList)):
    for key in wordList[doc].keys():
        if invert_index.get(key) == None:   #单词还不在索引中
            invert_index[key] = [0,0,0,0]
        invert_index[key][doc] += wordList[doc][key]

print("\n\n倒排索引：\n")  
for key in invert_index.keys():
    print("%-10s" %key ," : ", str(invert_index[key]))
