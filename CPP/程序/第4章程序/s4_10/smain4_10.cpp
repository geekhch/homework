//主文件
//文件名：s4_10\smain4_10.cpp

#include "sclass4_10_operator.h"		//包含类声明头文件

//主程序
int main()    
{ 
	COperator oCO1, oCO2(10);

  	oCO1 = ++oCO2;			//此处为重载的前缀++,因为oCO2是COperator的对象
							//oCO1()调用重载(),因为oCO1是COperator的对象
  	cout << "前缀++: " << oCO1() <<  " = " <<  oCO2.m_v << endl; 

  	oCO1 = oCO2++;			//此处为重载后缀++,因为oCO2是COperator的对象
  	cout << "后缀++: " <<  oCO1.m_v <<  " < " <<  oCO2.m_v << endl; 

 
  	oCO1 = 10;				//调默认运算符＝及类型隐式转换，将10赋值给对象
  	cout << "赋值＝: " <<  oCO1.m_v << endl;  
  	oCO2 = oCO2 + oCO1;
  	cout << "对象+对象: " <<  oCO1.m_v <<  "; " <<  oCO2.m_v<< endl;  	

  	cout << "对象>对象: " <<  (oCO2 > oCO1) << endl;  
  	cout << "对象<=对象: " << (oCO2 <= oCO1) << endl;  

	system("PAUSE");		//等待键盘输入以实现暂停  
	return 0;				//返回0
}

