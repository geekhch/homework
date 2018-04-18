// 文件路径名:s6_18\smain6_18.cpp
#include <iostream>               			// 编译预处理命令
#include <vector>							// 编译预处理命令
#include <string>			          		// 编译预处理命令
#include <algorithm>			          	// 编译预处理命令
using namespace std;						// 使用命名空间std 

// 定义学生类
class Student
{
private:
// 数据成员:
	int num;								// 学号
	string name;							// 姓名
	int age;								// 年龄
	string sex;								// 性别

public:
// 公有成员:	
	Student(int n, const string &nm, int ag, const string &sx): num(n), name(nm), age(ag), sex(sx){}
		// 构造函数
	int GetNum() const						// 返回学号
	{
		return num;							// 返回学号num
	}
	string GetName() const					// 返回姓名
	{
		return name;						// 返回姓名name
	}
	int GetAge() const						// 返回年龄
	{
		return age;							// 返回年龄age
	}
	string GetSex() const					// 返回性别
	{
		return sex;							// 返回性别sex
	}
	bool operator==(int n)					// 重载相等运算符" =="
	{
		return num == n;					// 转化为学号的比较
	}
};

int main()									// 主函数main()
{
	vector <Student> v;						// 定义向量对象

	v.push_back(Student(20120101, "张杰明", 18, "男"));	// 向v尾插入一个学生信息
	v.push_back(Student(20120102, "吴晓珊", 20, "女"));	// 向v尾插入一个学生信息
	v.push_back(Student(20120103, "吴洪倩", 19, "女"));	// 向v尾插入一个学生信息

	vector<Student>::iterator begin, end, it;		// 定义迭从器
	begin = v.begin();						// 开始
	end = v.end();							// 结束

	int findNum = 20120102;					// 查询条件是学号=20120102
	it = find(begin, end, findNum);			// 查询条件是学号=20120102的迭代器
	
	cout << "学号为" << findNum << "的学生的信息:" << endl;	// 输出提示
	if (it != end)
	{	// 查询成功
		cout << "学号:" << it->GetNum() << endl;			// 输出学号
		cout << "姓名:" << it->GetName() << endl;			// 输出姓名
		cout << "年龄:" << it->GetAge() << endl;			// 输出年龄
		cout << "性别:" << it->GetSex() << endl;			// 输出性别
	}
	else
	{	// 查询失败
		cout << "没有该学号的学生!" << endl;// 输出提示
	}

	system("PAUSE");            			// 调用库函数system( )，输出系统提示信息
	return 0;                    			// 返回值0, 返回操作系统
}
