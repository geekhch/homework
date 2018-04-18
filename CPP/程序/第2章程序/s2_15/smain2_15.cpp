// 文件路径名: s2_15\smain2_15.cpp
#include "sclass2_15_cpoint.h"
int main( ) 
{ 
	Point *p1= new Point( 1, 1);    
	Point *p2= new Point( 1, 3);
    Point *p3= new Point( 3, 3);
    cout <<"已创建的点数是："<<Point::GetCounter() <<endl;
    delete p1;
    delete p2;
    delete p3;
    return 0; 
}
