// 文件路径名:s1_6\main.cpp
#include <iostream>
using namespace std;

int max(int a,int b,int c)
{
   if (b>a) a=b;
   if (c>a) a=c;
   return a;
}
float max(float a,float b,float c)
{
 	if (b>a) a=b;
    if (c>a) a=c;
    return a;
}
long max(long a,long b,long c)
{
  	if (b>a) a=b;
    if (c>a) a=c;
    return a;
}
int main( )
{
	int a,b,c; 
	float d,e,f;
	cin>>a>>b>>c;
    cin>>d>>e>>f;
    int m; 
    m=max(a,b,c); 
    cout<<"max_i="<<m<<endl;
    float n;
    n=max(d,e,f); 
    cout<<"max_f="<<n<<endl;
    return 0;                    		// 返回值0, 返回操作系统
}
