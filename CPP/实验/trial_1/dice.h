#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Dice 
{
public:
    void do_dice();
    bool filish = false;
    
private: 
    int dice1;
    int dice2;
    int score = 0   ;
    int score1;
    string end;
    int count = 1;
};

void Dice::do_dice()
{
    srand((u_int)time(0));
    dice1 = rand()%6+1;
    srand((u_int)time(0)+5);
    dice2 = rand() % 6 + 1;
    score = dice1+dice2+score;
    if(count==1)
    {
        switch(score)
        {
            case 2:case 3:case 12: 
                cout << "本次骰子点数为：" << dice1 << "、" << dice2 << endl;
                cout << "当前点数和为:" << score << ",您输了!" << endl << endl;
                score = 0;
                filish = true;
                break;
            case 7: case 11:
                cout << "本次骰子点数为：" << dice1 << "、" << dice2 << endl;
                cout << "当前点数和为:" << score << ",您赢了!" << endl << endl;
                filish = true;
                break;
            default:
                cout << "本次骰子点数为：" << dice1 << "、" << dice2 << endl;
                cout << "当前点数和为:" << score << ",请继续投掷：" << endl;
                score1 = score;
        }
    }
    else
    {
        cout << "本次骰子点数为：" << dice1 << "、" << dice2 << endl;

        if (score == 7 || score > 12)
        {
            cout << "当前点数和为:" << score << ",您输了!" << endl
                 << endl;
            filish = true;
        }
        else if (score == score1)
        {
            cout << "当前点数和为:" << score << ",您赢了!" << endl
                 << endl;
            filish = true;
        }
        else 
        {
            cout << "当前点数和为:" << score << ",请继续投掷：" << endl;
        }
    }
    count += 1;
}