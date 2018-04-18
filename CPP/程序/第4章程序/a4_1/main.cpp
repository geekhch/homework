// �ļ�·����:a4_1\main.cpp
#include <iostream>               				// ����Ԥ��������
using namespace std;							// ʹ�������ռ�std 

class String
{
private:
// ���ݳ�Ա
	char *strValue;								// ��ֵ

public:
// ���г�Ա	
	String(char *s = "")						// ���캯��
	{
		if (s == NULL) s = "";					// ����ָ��ת��Ϊ�մ�
		strValue = new char[strlen(s) + 1];		// ����洢�ռ�
		strcpy(strValue, s);					// ���ƴ�ֵ
	}
	String(const String &copy)					// ���ƹ��캯��
	{
		strValue = new char[strlen(copy.strValue) + 1];	// ����洢�ռ�
		strcpy(strValue, copy.strValue);		// ���ƴ�ֵ
	}
	String &operator=(const String &copy);		// ���ظ�ֵ�����
	~String() { delete []strValue; }			// ��������
	void Show() const { cout << strValue <<  endl; }	// ��ʾ��
	
};

String &String::operator=(const String &copy)	// ���ظ�ֵ�����
{
	if (this != &copy)
	{	// Ŀ�Ķ�����Դ������ͬһ������
		delete []strValue;						// �ͷŴ洢�ռ�
		strValue = new char[strlen(copy.strValue) + 1];	// ����洢�ռ�
		strcpy(strValue, copy.strValue);		// ���ƴ�ֵ
	}
	return *this;								// ����Ŀ�Ķ���
}

int main()										// ������main()
{
	String s1("try"), s2, s3(s1);				// �������
	s2 = s1;									// ʹ�����ظ�ֵ�����
	
	s1.Show();									// ��ʾ��s1
	s2.Show();									// ��ʾ��s2
	s3.Show();									// ��ʾ��s3

	system("PAUSE");							// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;               					// ����ֵ0, ���ز���ϵͳ
}
