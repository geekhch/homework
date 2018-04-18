//主文件
//文件名：ch4_5\smain4_5.cpp

#include "sclass4_5_student.h"	//包含类声明头文件

//主测试程序
void main()    
{
	CPerson oCP(7, 'm', "比尔.盖茨");						//创建一个CPerson类的对象
	CStudent oCS(8, 'f', "希拉里.克林顿", "Grade Two");		//创建一个CStudent类的对象
	CClerk oCC(9, 'm', "谢尔盖.布林", 5000.1);				//创建一个CClerk类的对象
	COnJobStudent oCO(10, 'm', "拉里.佩奇", "Grade One", 4999.9);	//创建一个在职学生对象。

	cout<<"\n1:-通过基类的引用调用不同的Show( ):"<<endl;
	Reference(oCP);					//以基类对象作引用参数
	Reference(oCS);					//以派生类对象oCS作引用参数
	Reference(oCC);					//以派生类对象oCT作引用参数
	Reference(oCO);					//以派生类对象oCO作引用参数

	cout<<"\n2:-通过基类指针调用不同的Show( ):"<<endl;
	CPerson *poCP;					//定义一个基类指针
	poCP = &oCP;					//指向基类CPerson类对象
	poCP->Show();					//调用CPerson类的Show()
	poCP = &oCS;					//指向派生类CStudent类对象
	poCP->Show();					//调用CStudent类的Show()
	poCP = &oCC;					//指向派生类CTeacher类对象
	poCP->Show();					//调用CTeacher类的Show()
	poCP = &oCO;					//指向二级派生类对象oCO
	poCP->Show();					//调用COnJobStudent类的Show();
									//说明通过基类指针可调用二级派生的虚函数，即虚函数具有传递性。

	cout<<"\n3:-通过一级派生类指针调用二级派生类的Show( ):"<<endl;
	CStudent *poCS = &oCO;			//上一级指针指向下一级类对象
	poCS->Show();					//调用COnJobStudent类的Show()
	COnJobStudent *poCO = &oCO;		//本类指针指向本类对象
	poCO->Show();					//调用COnJobStudent类的Show()

	cin.get();  
}
