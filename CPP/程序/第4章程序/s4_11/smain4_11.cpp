//主文件
//文件名：s4_11\smain4_11.cpp

#include <iostream>  					//包含头文件,使用iostream库
#include "sclass4_11_Node.h"			//包含类声明头文件

int CNode::sNodeNum = 0;
/*****************************************************************************/

//主函数: 本例的设计思路主要是为了便于学习和观察相关C++机制!!
//调整作用域运行程序，仔细观察、体会可加深对相关概念的理解。
void main( )
{
	cout << "1********************************************." <<endl;
	//第一段作用域，主要观察拷贝构造函数和new、delete运算符的作用	
	{
		CNodeArray oCNA1;				//创建一个节点管理类对象
		// 内部作用域，去掉注释可观察到oCN1和oCN2的析构位置
		{
			int i;
			char s[81];						//暂时存放获取的节点名字
			string str;						//创建一个string对象
			//CNode oCN1("Zhang San"),oCN2("Li Si");//创建两对象
			//oCN2 = oCN1;					//调用重载的赋值运算符
			CNode *poCN1, *poCN2;			//定义一个CNode指针
			for (i=0; i<5; i++)
			{
				cout << "Input a Node Name or word \"stop\" : ";
				cin.getline(s,81,'\n');	//输入字符串作为节点名,str=gets(s);
				str = s;					//字符串转换为字符串对象
				if (str=="stop")			//如果输入字符串为"stop",则退出
					break;
				poCN1 = new CNode( str );	//调用一般构造函数新建对象
				poCN2 = new CNode( *poCN1 );//调用拷贝构造函数新建对象
				oCNA1.Insert( *poCN1 );		//节点数组指针指向该对象
				oCNA1.Insert( *poCN2 );		//节点数组指针指向该对象
			}
		}
		cout << "*****START*******************************." <<endl;
		cout << oCNA1[0];					//观察重载的"<<"和"[ ]"运算符
		cout << "*****END*********************************." <<endl;
		for (int i=0; i<5; i++)
		{
			oCNA1.Delete(i);		//注释掉本语句可观察到delete的作用
		}
	}
	
	cout << "2********************************************." <<endl;
	//第二段作用域，主要观察重载的new和delete的调用
	{
		CNode oCN1("Genghis khan");				//元太祖,名铁木真
		CNodeArray *poCN3 = new CNodeArray;		//调用重载"new"
		delete poCN3;	//调用重载delete,注通过::delete可调系统delete
	}
	cout << "3********************************************." <<endl;
	//第三段作用域，主要观察重载的"<<、>>、,、="运算符的调用
	{
		CNode oCN1("Genghis khan"), oCN2("11"), oCN3(oCN1);	//元太祖,名铁木真
		cin >> oCN3;				// 调用重载的">>"运算符	
		cout << oCN3;				// 调用重载的"<<"运算符	
		oCN3 = oCN2, oCN1;			// 调用重载的","和"="运算符
		cout << oCN3;				// 调用重载的"<<"运算符	
	}
}

