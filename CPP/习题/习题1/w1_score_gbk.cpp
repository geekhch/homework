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
    cout << "�㿼�Կ��˶��ٷ֣�" << endl;
    cin >> score;
    int flag = score/10;
    switch(flag)
    {
        case 10:
        case 9: cout << "��" << endl; break;
        case 8: cout << "��" << endl; break;
        case 7:
        case 6: cout << "��" << endl; break;
        default: cout << "��" << endl; break;
    }
    cin >> score;
    return 0;
}