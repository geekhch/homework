#include <iostream>
#include "GetArea.h"
using namespace std;
/* ����������ͬ���͵����ĳ˻������ص�һ���������͵�ֵ */

int main(int argc, char** argv) {
	double x = 1.5;
	float y = 4.2;
	int z = 3;
	GetArea<double, float, int> m1(x,y,z);
	GetArea<int, double, float> m2(z,x,y);
	cout << m1.execute() << endl;
	cout << m2.execute() << endl;
	return 0;
}
