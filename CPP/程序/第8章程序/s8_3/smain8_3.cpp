//文件名：s8_3\smain8_3.cpp
//内存的三种传递方法比较

#include <iostream>
using namespace std;

//利用指针传值
char *TestPointerForwardValue(char *pChar2)
{
	char *pChar = new char[strlen(pChar2)+1];	//注意与sizeof(pChar2)区别
	if (NULL == pChar)							//比 pChar == NULL更安全
	{
		exit(1);
	}
	strcpy(pChar, pChar2);	
	cout<< pChar << endl;
	return pChar;
}

//利用指针的引用传值
char *TestReferencePointer(char *&rpChar)		//利用指针的引用传值
{
	char *pChar = new char[strlen(rpChar)+1];	//注意与sizeof(rpChar)区别
	if (NULL == pChar)							//此法可避免误写成赋值语句
	{
		exit(2);
	}
	strcpy(pChar, rpChar);	
	cout<< pChar << endl;
	return pChar;
}

//利用返回指针传值：传递动态内存。如传递栈内存会出错。
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
	cout<< b << endl;						// 输出复制到栈内存中的字符串
	strcpy(pChar, a);
	strcat(pChar, pConst);
	return pChar;	// 如改成return b，则返回了栈内存，最后的输出是无效内容
}

//利用返回指针传值：传递静态存储区内存空间。
char *TestReturnStaticMemory( )
{
	char *p = "Diaoyu islands is Chinese inherent territory.";
	cout<< p << endl;					// 输出静态内存中的字符串
	return p;	
}

//测试函数
int main()
{
	char a1[] = "Hello, Sichuan University!";  	
	char *p1 = a1;
	char a2[] = "Hello, College of Computer!";
	char *p2 = a2;
	char *p = NULL;
	cout << sizeof(a1) << "; " << strlen(p1) << endl;	// 注意前后的长度的差异
	p = TestPointerForwardValue(p1);
	cout<< p << endl;						// 打印返回的动态内存区域中的字符串
	delete []p;
	p = TestReferencePointer(p2);
	cout<< p << endl;						// 打印返回的动态内存区域中的字符串
	delete []p;
	p = TestReturnDynamicMemory(a2);
	cout<< p << endl;						// 打印返回的动态内存区域中的字符串
	delete []p;
	p = TestReturnStaticMemory();
	cout<< p << endl;						// 打印返回的静态存储区域中的字符串

	system("PAUSE");			//等待键盘输入以实现暂停  
	return 0;					//返回0
}