#include <iostream>
#include <string>
#define PI 3.14159
using namespace std;

class Circle
{
public:
    Circle(double radius = 5){this->radius = radius;};
    inline double getRadius();
    inline double getPrimeter();
    inline double getArea();
    inline void printInfo();
private:
    double radius; //Ĭ�ϰ뾶Ϊ5
};

inline double Circle::getRadius(){
    return radius;
}

inline double Circle::getPrimeter(){
    return 2*PI*radius;
}

inline double Circle::getArea(){
    return PI*radius*radius;
}

inline void Circle::printInfo(){
    cout << "Բ�İ뾶Ϊ" << getRadius() << endl;
    cout << "�ܳ�Ϊ" << getPrimeter() <<endl;
    cout << ",���Ϊ" << getArea() << endl;
}