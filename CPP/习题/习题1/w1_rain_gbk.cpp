/**
 * ��дһ������ʵ�����¹��ܣ����û����ʡ��������������𣿡���
 * ��ʾ����Y��N��������ΪY����ʾ�������������ꡱ��
 * ������ΪN����ʾ������û�����ꡱ��
 * */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "������������(Y or N)"<< endl;
    string answer;
    cin >> answer;
    if(answer.compare("Y") == 0){
        cout << "������������" << endl;
    }
    if(answer.compare("N") == 0){
        cout << "����û������" << endl;
    }
    
    cin >> answer;//��ͣ
    return 0;
}