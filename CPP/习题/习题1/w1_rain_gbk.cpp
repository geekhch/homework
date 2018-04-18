/**
 * 编写一个程序实现以下功能：向用户提问“现在正在面雨吗？”，
 * 提示输入Y或N。若输入为Y则显示“现在正在下雨”，
 * 若输入为N则显示“现在没有下雨”。
 * */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "现在在下雨吗？(Y or N)"<< endl;
    string answer;
    cin >> answer;
    if(answer.compare("Y") == 0){
        cout << "现在正在下雨" << endl;
    }
    if(answer.compare("N") == 0){
        cout << "现在没有下雨" << endl;
    }
    
    cin >> answer;//暂停
    return 0;
}