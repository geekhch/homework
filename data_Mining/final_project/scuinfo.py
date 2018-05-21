#coding:utf-8

import time
from selenium import webdriver
from lxml import etree
from sqlSet import Mysql
import re
from selenium.webdriver.common.keys import Keys
#这里一定要设置编码格式，防止后面写入文件时报错

print("准备打开浏览器")
driver = webdriver.Firefox()  
print("打开浏览器")
driver.maximize_window()

driver.get("https://scuinfo.com/") 
time.sleep(1)
driver.find_element_by_css_selector('body').click()
for i in range(1, 20000):
    driver.find_element_by_xpath("//body").send_keys(Keys.DOWN)
    time.sleep(0.001)

selector = etree.HTML(driver.page_source)
divs = selector.xpath('//div[@id="homeList"]/div[@style="padding: 12px 25px 4px; border-bottom: 12px solid rgb(242, 242, 242);"]')             
#这里使用 a 表示内容可以连续不清空写入
with open('scuinfo.txt','a',encoding='utf-8') as f:
    for div in divs:
        content = div.xpath('./div[2]/div[1]/span/text()')
        comment_num = div.xpath('./div[2]/div[2]/div[2]/div[1]/div[2]/text()')
        name = div.xpath('./div[1]/div[1]/div[2]/text()')
        good_num = div.xpath('./div[2]/div[2]/div[2]/div[2]/div[2]/text()')
        if not content:
            continue
        if not name:
            name = ['null']
        if not comment_num:
            comment_num = ['0']
        if not good_num:
            good_num = ['0']
        item = [content, name, comment_num, good_num]
        try:
            f.write(str(item)+"\n")
        except:
            print("写入错误")
