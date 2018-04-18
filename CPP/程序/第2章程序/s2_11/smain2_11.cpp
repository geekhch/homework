// 文件路径名: s2_11\smain2_11.cpp
#include "sclass2_11_rectangle.h"
int main() 
{
	//为一个长10宽5的长方形动态分配内存，并让指针rp指向这块内存
	Rectangle *rp= new Rectangle(10,5);  //定义对象指针
	rp->Print();      //调用rp所指向的对象的成员函数print() 
	rp->SetSize(45, 20); 
	cout<<"长45宽20的长方形的面积是"<< rp->GetArea()<<endl;
	delete rp;        //释放指针rp所指向的存储空间
	return 0; 
}

