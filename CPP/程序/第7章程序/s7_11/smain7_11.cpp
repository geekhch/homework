// �ļ�·����:s7_11\smain7_11.cpp
#include <iostream>               		// ����Ԥ��������
#include <fstream>               		// ����Ԥ��������
using namespace std;					// ʹ�������ռ�std 

struct Student							// ѧ���ṹ
{
	int num;							// ѧ��
	char name[16];						// ����
	float score;						// �ɼ�
};

int main()								// ������main()
{
	Student stu[3] =					// ��������
	{
		{2009101, "��ٻ", 68}, 
		{2009102, "����", 89}, 
		{2009103, "��ǿ", 98}
	};
	
	fstream f("stu.dat", ios::out | ios::binary);			// �����ļ�����,����ļ������ڽ�����һ�����ļ�
	f.close();							// �ر��ļ�
	f.open("stu.dat", ios::in | ios::out | ios::binary);	// �������������ʽ���ļ�
	if (f.fail())	
	{	// ���ļ�ʧ��
		cout << "���ļ�ʧ��!" << endl;
		exit(1);						// �˳�����
	}

	f.write((char *)&stu[0], sizeof(stu));	// д���ݵ��ļ���

	Student s;							// ���ڴ洢��2��ѧ����Ϣ
	f.seekp((2 - 1) * sizeof(Student), ios::beg);			// ��λ�ڵ�2��ѧ�����ݵ���ʼλ��
	f.read((char *)&s, sizeof(Student));// ������2��ѧ������Ϣ
	s.score = 99;						// �޸ĵ�2��ѧ������Ϣ
	f.seekp((2 - 1) * sizeof(Student), ios::beg);			// ��λ�ڵ�2��ѧ�����ݵ���ʼλ��
	f.write((char *)&s, sizeof(Student));					// д���2��ѧ������Ϣ

	f.seekg(0);							// ���¶�λ���ļ���ʼ��
	f.read((char *)&s, sizeof(Student));// ����ѧ������Ϣ
	while (!f.eof())
	{	// �ļ�δ����
		cout << s.num << " " << s.name << " " << s.score << endl;	// ��ʾѧ����Ϣ
		f.read((char *)&s, sizeof(Student));				// ����ѧ������Ϣ
	}	
	f.close();							// �ر��ļ�

	system("PAUSE");            		// ���ÿ⺯��system()�����ϵͳ��ʾ
	return 0;                    		// ����ֵ0, ���ز���ϵͳ
}
