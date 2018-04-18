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
    double radius; //默认半径为5
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
    cout << "圆的半径为" << getRadius() << endl;
    cout << "周长为" << getPrimeter() <<endl;
    cout << ",面积为" << getArea() << endl;
}