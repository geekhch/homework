#include <iostream>


template<class T1, class T2, class T3>
class GetArea
{
public:
	GetArea(T1, T2, T3);
	T1 execute();
private:
	T1 x;
	T2 y;
	T3 z;
};

template<class T1, class T2, class T3>
GetArea<T1, T2, T3>::GetArea(T1 x, T2 y, T3 z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template<class T1, class T2, class T3>
T1 GetArea<T1, T2, T3>::execute()
{
	return (T1)x*y*z;
}
