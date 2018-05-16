#include <list>
#include <stdio.h>

#include <iostream>
using namespace std;

int main()
{
    int num;
    list<int> list_int;
    cout << "请输入整数序列,以终止符结束(WIN:CTRL + Z,  LINUX: CTRL + D)" << endl;
    while(scanf("%d", &num) != EOF)
    {
        list_int.push_back(num);
    }
    cout << "反向输出序列:" << endl;
    while(!list_int.empty())
    {
        num = list_int.back();
        cout << num << " ";
        list_int.pop_back();
    }
    cout << "输出结束" << endl;
    return 0;
}