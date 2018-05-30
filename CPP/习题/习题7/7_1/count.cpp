#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    string name, stu_n, score;
    cin >> name >> stu_n >> score;
    fstream file;
    file.open("stu.dat", ios::in|ios::out);
    file << name << stu_n << score << endl;
    file.close();
    return 0;
}