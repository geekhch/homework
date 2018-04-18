#include <iostream>
using namespace std;

class Time
{
public:
    Time():h(0),m(0),s(0){}
    Time(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }
    void printTime()
    {
        cout << h << ":" << m << ":" << s << endl;
    }
private:
    int h,m,s;
};