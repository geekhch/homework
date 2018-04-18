//类的实现文件
//文件名：s4_10\sclass4_10_operator.cpp

#include "sclass4_10_operator.h"		//包含类声明头文件

//构造函数
COperator::COperator(int b): m_v(b)
{
	;
}
 	
int COperator::operator++(int i)	//重载后缀++，先取值，后自加
{
	int iRV = m_v;					//创建一个临时对象，原来保存对象原来的值
	if(m_v<65635)
    	m_v++;						//此处++为系统默认含义;因为m_v是基本数据类型
	else					 
		m_v = 0;					//超过65535则置0
	return iRV;						//返回对象原值，也就是修改前的值
}
  
int COperator::operator++()			//重载前缀++，先自加，后取值
{
	if(m_v<65635)
    	m_v++;						//此处++为系统默认含义;因为m_v是基本数据类型
	else					
		m_v = 0;					//超过65535则置0
	return m_v;						//返回修改后的对象值
}
  
int COperator::operator()()			//重载函数运算符，功能：取m_v的值
{
 	return m_v;
}

COperator COperator::operator+(const COperator &ob)	//重载算术运算符:对象+对象
{
	int v = m_v + ob.m_v;			//将两个对象的m_v值相加，作为返回对象的值
	if (m_v>65635)
		v = v - 65636;				//保证m_v的值在0～65635之间
	return COperator(v);
}

bool COperator::operator>(const COperator &ob)		//重载比较运算符:对象>对象
{
	if (m_v > ob.m_v)
		return true;
	else
		return false;
}

bool COperator::operator<=(const COperator &ob)	//重载比较运算符:对象<=对象
{
	if (m_v <= ob.m_v)
		return true;
	else
		return false;
}