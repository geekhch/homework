//�ļ�·������s2_4\sclass2_4_ Square.cpp
#include "sclass2_4_square.h"
Square::Square(double s)
{
	side=s;  
} 
double Square::GetSide() 
{
	return side;  
} 
double Square::GetCircumference() 
{
	return 4*side ;
} 
double Square::GetArea()
{
	return side *side ;
}
void Square::Print()
{
	cout<<"�߳�Ϊ" <<side<<"�������ε��ܳ��ǣ�"<< 4*side<<"������ǣ�"<< side *side <<endl;
} 
