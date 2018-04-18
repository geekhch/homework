//文件路径名：s2_4\sclass2_4_ Square.cpp
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
	cout<<"边长为" <<side<<"的正方形的周长是："<< 4*side<<"，面积是："<< side *side <<endl;
} 
