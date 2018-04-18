// 文件路径名: s2_18\smain2_18.cpp
#include<iostream>
using namespace std;
class CSample
{           
public:	
	CSample(){};							//空构造函数
	void MemberFunc(int a)					//成员函数
	{
		i=a;
	}
	friend void FriendFunc(CSample *, int);	//声明一个友元函数
private:	
	int i;
};
void FriendFunc(CSample *p, int a)			//友元函数FriendFunc的实现
{
	p->i = a;  
	cout<<"i="<< p->i<<endl;                
}
int main()
{
	CSample *p=new CSample;
	FriendFunc(p , 3); 
	delete p;    
	return 0;   
}
