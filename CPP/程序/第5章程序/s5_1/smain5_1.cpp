//s5_1\smain5_1.cpp
//ͨ��ģ��ʵ����������̫�ܹ�������������һ��

#include <iostream>
#include <string>

using namespace std;

//���庯��ģ��
template <class Type>
Type GetMax(Type a, Type b, Type c)
{
	Type t;
	t = a>b ? a:b;			//��a��b�Ľϴ���
	return t>c ? t:c;		//����a��b��c������ߡ�
}

//������
int main()    
{
	string str1("Rong Ji"), str2("Zhe Ming"), str3("Jing Tao");
	//ʹ�ú���ģ��
	cout << "int:10, 30, 21, max=" << GetMax(10, 30, 21) << endl;
	cout << "double:51.8,20.8,31.6,max="<<GetMax(51.8,20.8,31.6)<<endl; 
	cout << "char:'A','b','Z',max="<<GetMax('A','b','Z')<<endl; 
	cout << "string: str1(\"Rong Ji\"), str2(\"Zhe Ming\"), str3(\"Jing Tao\")," 
		"max=" << GetMax(str1,str2,str3) << endl;	//ע�������ַ�������Ȼ����	
	//cout << "'A','b',97,max="<<GetMax('A','b',97)<<endl; //��������ģ�����Ͳ�����������ʽ����ת��������

	system("PAUSE");		//�ȴ�����������ʵ����ͣ  
	return 0;				//����0
}

