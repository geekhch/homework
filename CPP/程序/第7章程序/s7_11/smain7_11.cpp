// 文件路径名:s7_11\smain7_11.cpp
#include <iostream>               		// 编译预处理命令
#include <fstream>               		// 编译预处理命令
using namespace std;					// 使用命名空间std 

struct Student							// 学生结构
{
	int num;							// 学号
	char name[16];						// 姓名
	float score;						// 成绩
};

int main()								// 主函数main()
{
	Student stu[3] =					// 定义数组
	{
		{2009101, "李倩", 68}, 
		{2009102, "刘杰", 89}, 
		{2009103, "王强", 98}
	};
	
	fstream f("stu.dat", ios::out | ios::binary);			// 定义文件对象,如果文件不存在将建立一个空文件
	f.close();							// 关闭文件
	f.open("stu.dat", ios::in | ios::out | ios::binary);	// 再以输入输出方式打开文件
	if (f.fail())	
	{	// 打开文件失败
		cout << "打开文件失败!" << endl;
		exit(1);						// 退出程序
	}

	f.write((char *)&stu[0], sizeof(stu));	// 写数据到文件中

	Student s;							// 用于存储第2个学生信息
	f.seekp((2 - 1) * sizeof(Student), ios::beg);			// 定位于第2个学生数据的起始位置
	f.read((char *)&s, sizeof(Student));// 读出第2个学生的信息
	s.score = 99;						// 修改第2个学生的信息
	f.seekp((2 - 1) * sizeof(Student), ios::beg);			// 定位于第2个学生数据的起始位置
	f.write((char *)&s, sizeof(Student));					// 写入第2个学生的信息

	f.seekg(0);							// 重新定位于文件开始处
	f.read((char *)&s, sizeof(Student));// 读出学生的信息
	while (!f.eof())
	{	// 文件未结束
		cout << s.num << " " << s.name << " " << s.score << endl;	// 显示学生信息
		f.read((char *)&s, sizeof(Student));				// 读出学生的信息
	}	
	f.close();							// 关闭文件

	system("PAUSE");            		// 调用库函数system()，输出系统提示
	return 0;                    		// 返回值0, 返回操作系统
}
