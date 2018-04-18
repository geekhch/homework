//文件路径名:s2_13\smain2_13.cpp
#include "sclass2_13_sample.h"
int main()
{
	CSample s1(10);
	CSample s2(20);
	CSample s3;
	s3.Add(s1, s2);    //调用Add()，将对象s1和s2的数据成员n相加
	cout << "s3.n = " << s3.GetN() << endl;
	return 0;
}
