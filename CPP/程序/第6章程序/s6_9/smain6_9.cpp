// �ļ�·����:s6_9\smain6_9.cpp
#include <iostream>               			// ����Ԥ��������
#include <string>	              			// ����Ԥ��������
#include <list>			          			// ����Ԥ��������
using namespace std;						// ʹ�������ռ�std 
    
typedef list<string> StrList;				// ���Ͷ���

int main()									// ������main()
{
	StrList la;								// �����������
	
	la.push_back("back");					// ������β�����"back"
	la.push_front("middle");				// ��������Ԫ��ǰ����"middle"
	la.push_front("front");					// ��������Ԫ��ǰ����"front"
    
	cout << la.front() << endl;				// �����Ԫ��"front"
	cout << *la.begin() << endl;			// �����Ԫ��"front"
	cout << la.back() << endl;				// ���βԪ��"back"
	cout << *la.rbegin() << endl;			// ���βԪ��"back"
	la.pop_front();							// ɾ��"front"
	la.pop_back();							// ɾ��"back"
	cout << la.front() << endl;				// ���"middle"

	system("PAUSE");            			// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;                    			// ����ֵ0, ���ز���ϵͳ
}
