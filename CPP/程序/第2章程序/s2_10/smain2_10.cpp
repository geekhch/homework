// 文件路径名: s2_10\smain2_10.cpp
#include "sclass2_10_cpoint.h"
int main() 
{ 
	CPoint *p= new CPoint[5];	//声明并初始化对象数组p，为其动态分配内存空间
	int i;
	for (i=0;i <5;i++) 
	{ 
		p[i].Move(i,i);			//将数组p下标为i的对象元素的横、纵坐标值都设为i 
	} 
	for (i=0;i<5;i++) 
	{  	    
		//输出数组p的下标为i的对象元素的横、纵坐标，因为数据成员x和y都是
		//公有的访问权限，所以可以在类外由对象元素直接访问
		cout <<p[i].x <<"," <<p[i].y <<endl; 
	} 
	delete []p;  //释放数组p所占用的空间
	return 0; 
}
