//主文件名：s3_1\smain3_1.cpp
#include "sclass3_1_A.h"   
int main()
{
	B ObjB;
	ObjB.SetValue(1, 2, 3, 4, 5);
	ObjB.Display();
	cout << "z = "<< ObjB.z << endl;	//公有数据，可通过对象访问
	// cout << "y="<< ObjB.y << endl;	//基类的保护数据，不可通过对象访问
	// cout << "x="<< ObjB.x << endl;	//基类的私有数据，类外均不可访问
	// cout << "m="<< ObjB.m << endl;	//派生类的保护数据，不可通过对象访问
	// cout << "n="<< ObjB.n << endl;	//派生类的私有数据，不可通过对象访问
	return 0;
}
