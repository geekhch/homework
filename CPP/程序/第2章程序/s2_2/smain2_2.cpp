// 文件路径名:s2_2\smain2_2.cpp
#include "sclass2_2_cdemo.h" 

int main()
{
	CDemo d;				//创建一个Demo类对象 
	d.SetI(10);				//调用SetI( ) 间接访问私有数据i并为i赋值为10
	d.SetJ(20);				//调用SetJ( ) 间接访问私有数据j并为i赋值为20
	d.GetI( );				//调用GetI( )间接访问私有数据i并输出其值
	d.GetJ( );				//调用GetJ( )间接访问私有数据j并输出其值
	return 0;
}
