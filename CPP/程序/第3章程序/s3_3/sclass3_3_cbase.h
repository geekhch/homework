//类的声明文件：s3_3\sclass3_3_cbase.h
#ifndef _SCLASS_3_3_CBASE_H
#define _SCLASS_3_3_CBASE_H
#include <iostream>  
using namespace std;  

// 声明基类：CBase
class CBase
{
public:
   	CBase() { n = 0; m = 0; }		//构造函数
	void SetValue(int a, int b);	//为数据成员m和n赋值		
	void CalcuValue();				//用于计算的接口，并将计算结果显示在屏幕上   		
protected:
	int m;							//保护成员
private: 
	int n;							//私有成员 
};

//声明派生类：CDerived。为其指定基类CBase及继承方式public。
class CDerived : public CBase 
{
public:
	CDerived() {}
	void SetJ();		
	void SetK();
	void DisplayVal() const;
private:
	int j;
	int k;
};
#endif
