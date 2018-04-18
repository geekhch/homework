/**
 * 
 * 
 * 
 * 
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int score;
    cout << "你考试考了多少分？" << endl;
    cin >> score;
    int flag = score/10;
    switch(flag)
    {
        case 10:
        case 9: cout << "优" << endl; break;
        case 8: cout << "良" << endl; break;
        case 7:
        case 6: cout << "中" << endl; break;
        default: cout << "差" << endl; break;
    }
    cin >> score;
    return 0;
}