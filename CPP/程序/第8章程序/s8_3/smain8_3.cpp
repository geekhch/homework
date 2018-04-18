//�ļ�����s8_3\smain8_3.cpp
//�ڴ�����ִ��ݷ����Ƚ�

#include <iostream>
using namespace std;

//����ָ�봫ֵ
char *TestPointerForwardValue(char *pChar2)
{
	char *pChar = new char[strlen(pChar2)+1];	//ע����sizeof(pChar2)����
	if (NULL == pChar)							//�� pChar == NULL����ȫ
	{
		exit(1);
	}
	strcpy(pChar, pChar2);	
	cout<< pChar << endl;
	return pChar;
}

//����ָ������ô�ֵ
char *TestReferencePointer(char *&rpChar)		//����ָ������ô�ֵ
{
	char *pChar = new char[strlen(rpChar)+1];	//ע����sizeof(rpChar)����
	if (NULL == pChar)							//�˷��ɱ�����д�ɸ�ֵ���
	{
		exit(2);
	}
	strcpy(pChar, rpChar);	
	cout<< pChar << endl;
	return pChar;
}

//���÷���ָ�봫ֵ�����ݶ�̬�ڴ档�紫��ջ�ڴ�����
char *TestReturnDynamicMemory(char a[])
{
	char b[100];
	char *pConst = "Sichuan University!";
	char *pChar = new char[strlen(a)+strlen(pConst)+1];	//
	if (NULL == pChar)
	{
		exit(3);
	}
	strcpy(b, a);
	cout<< b << endl;						// ������Ƶ�ջ�ڴ��е��ַ���
	strcpy(pChar, a);
	strcat(pChar, pConst);
	return pChar;	// ��ĳ�return b���򷵻���ջ�ڴ棬�����������Ч����
}

//���÷���ָ�봫ֵ�����ݾ�̬�洢���ڴ�ռ䡣
char *TestReturnStaticMemory( )
{
	char *p = "Diaoyu islands is Chinese inherent territory.";
	cout<< p << endl;					// �����̬�ڴ��е��ַ���
	return p;	
}

//���Ժ���
int main()
{
	char a1[] = "Hello, Sichuan University!";  	
	char *p1 = a1;
	char a2[] = "Hello, College of Computer!";
	char *p2 = a2;
	char *p = NULL;
	cout << sizeof(a1) << "; " << strlen(p1) << endl;	// ע��ǰ��ĳ��ȵĲ���
	p = TestPointerForwardValue(p1);
	cout<< p << endl;						// ��ӡ���صĶ�̬�ڴ������е��ַ���
	delete []p;
	p = TestReferencePointer(p2);
	cout<< p << endl;						// ��ӡ���صĶ�̬�ڴ������е��ַ���
	delete []p;
	p = TestReturnDynamicMemory(a2);
	cout<< p << endl;						// ��ӡ���صĶ�̬�ڴ������е��ַ���
	delete []p;
	p = TestReturnStaticMemory();
	cout<< p << endl;						// ��ӡ���صľ�̬�洢�����е��ַ���

	system("PAUSE");			//�ȴ�����������ʵ����ͣ  
	return 0;					//����0
}