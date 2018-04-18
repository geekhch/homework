//�ļ�����s8_5\smain8_5.cpp
//�쳣ʾ��

#include <iostream>
#include <string>
using namespace std;

class CMyException 							//�����쳣��
{
public:
    CMyException(){}
    ~CMyException(){}
    const char *GetExceptionReason() const	//��ʾ�쳣ԭ��
	{ return "CMyException Exception."; }
};

class CDemo				//����һ�������࣬������ʾ��ִ�����쳣�׳���˳��
{
public:
    CDemo() { cout << "Constructing CDemo." << endl; }
    ~CDemo() { cout << "Destructing CDemo." << endl; }
};

//�쳣Ҳ���Զ���װ�����磺��MyFunC()�з�װthrow��try��catch����
//�����ﲶ������쳣����ʵ����������main()�н������쳣������
void MyFunc()												
{
    CDemo D;
    cout << "\nIn MyFunc(). Throwing CMyException exception." << endl;
    throw CMyException();				//�׳��쳣
}

int main()
{
    try									//��try��װ���ܻ�����쳣�Ĵ���
    {
        cout << "In try block, calling MyFunc()." << endl;
        MyFunc();
    }
    catch(CMyException E)				//һ·���񲢴����쳣
    {
        cout << "Caught: ";
        cout << E.GetExceptionReason() << endl;
    }
    catch(string str)					//��·���񲢴����쳣
    {
        cout << "Caught some other exception: " << str << endl;
    }

	system("PAUSE");					//�ȴ�����������ʵ����ͣ  
	return 0;							//����0
}

