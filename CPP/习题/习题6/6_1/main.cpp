#include <iostream>
#include "complex.h"
#include <functional>
using namespace std;

int main()
{
    Complex a(4,3);
    Complex b(2.5,1.3);
    Complex c(0,0);
    a.toString();
    cout << "与";
    b.toString();
    cout << "之和为";
    c = a+b;
    c.toString();
    cout << endl;
    plus<Complex, Complex>{}(a, b);
    return 0;
}