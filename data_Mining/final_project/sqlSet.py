#coding=utf-8
import pymysql
import time

 class Mysql:
    m_conn = pymysql.connect(
        host='127.0.0.1', port=3306,
        user='root', password='123',
        db='qq', charset='utf8',
        cursorclass=pymysql.cursors.DictCursor)

    def getConn(self):
        return self.m_conn

    def update(self, sql):
        '''更新数据数据'''
        try:
            m_cursor = self.m_conn.cursor()
            # print(self.Time()+sql)
            m_cursor.execute(sql)
            self.m_conn.commit()
            m_cursor.close()
        except:
            print("%s更新数据库失败：" % self.Time() + sql)

    def querry(self, sql):
        '''查询数据'''
        try:
            m_cursor = self.m_conn.cursor()
            m_cursor.execute(sql)
            result = m_cursor.fetchall()
            return result
            m_cursor.close()
        except:
            print("%s查询数据库失败：" % self.Time() + sql)

    def Time(self):
        str = time.strftime("[%m-%d %H:%M]", time.localtime())
        return str

    def close(self):
        self.m_conn.close()
