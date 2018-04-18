#include "dice.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    cout << "是否开始游戏？（y输入开始，其他退出）";
    string command;
    cin >> command;
    while(command.compare("y") == 0)
    {
        fflush(stdin);
        Dice dice;
        while (command.compare("y") == 0)
        {
            fflush(stdin);
            dice.do_dice();
            cout << "(继续：y,其他输入退出)" << endl;
            if(dice.filish)
                break;
            cin >> command;
        }
        cout << "开始新游戏？（y开始，其他输入退出）" << endl;
        cin >> command;
    }
    cin.get();
    return 0;
}