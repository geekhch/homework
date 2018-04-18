//文件名：s3_8\smain3_8.cpp
#include <iostream>
using namespace std;

class B1	  //基类B1，构造函数有参数
{
public:
	B1(int ii): i(ii) {	cout<<"constructing B1，i= "<<i<<endl;	}
private:
	int i;
};

class B2	 //基类B2，构造函数有参数
{
public:
	B2(int jj): j(jj) {	cout<<"constructing B2，j= "<<this->j<<endl; }
private:
	int j;
};

class B3	//基类B3，构造函数无参数
{
public:
	B3() { cout<<"constructing B3 *"<<endl;	}
};

class C: public B2, public B1, public B3 
{
public:	
	C(int a, int b, int c ): B2(a), B1(b), k(c)	{ cout<<"constructing C，k= "<<k<<endl;	}
private:	
	int k;
};

int main()
{
	C obj(1,2,3);  
	return 0;
}
