// �ļ�·����:s2_14\smain2_14.cpp
#include "sclass2_14_cpoint.h "
int main() 
{
	Point *p1 = new Point(1, 1);    
	Point *p2 = new Point(1, 3);
    Point *p3 = new Point(3, 3);
   	cout << "�Ѵ����ĵ�����:" << Point::counter << endl; 
	delete p1;
	delete p2;
	delete p3;
    return 0; 
}
