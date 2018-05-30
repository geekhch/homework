#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    string name, stu_n, score;
    fstream file;
    file.open("stu.dat", ios::in|ofstream::out);
    while(cin >> name >> stu_n >> score){
        file << name << stu_n << score << endl;
        cout << name << stu_n << score << endl;
    }
    file << "fadf" << endl;
    file.close();
    return 0;
}