// 文件路径名:s6_5\smain6_5.cpp
#include <iostream>               			// 编译预处理命令
#include <functional>              			// 编译预处理命令
using namespace std;						// 使用命名空间std 

int main()									// 主函数main()
{
	// 下面定义一些算术函数对象
	plus<int> objPlus;						// 定义加法算术函数对象
	minus<int> objMinus;					// 定义减法算术函数对象
	multiplies<int> objMul;					// 定义乘法算术函数对象
	divides<int> objDiv;					// 定义除法算术函数对象
	modulus<int> objMod;					// 定义求余算术函数对象
	negate<int> objNeg;						// 定义取反算术函数对象
    
	// 下面运用上面定义的函数对象，实现相应的函数功能
	cout << objPlus(2, 6) << endl;			// 输出2+6
	cout << objMinus(2, 6) << endl;			// 输出2-6
	cout << objMul(2, 6) << endl;			// 输出2*6
	cout << objDiv(2, 6) << endl;			// 输出2/6
	cout << objMod(2, 6) << endl;			// 输出2%6
	cout << objNeg(2) << endl;				// 输出-2

	// 下面直接以生成的临时函数对象实现相关函数功能
	cout << plus<int>()(2, 6) << endl;		// 输出2+6
	cout << minus<int>()(2, 6) << endl;		// 输出2-6
	cout << multiplies<int>()(2, 6) << endl;// 输出2*6
	cout << divides<int>()(2, 6) << endl;	// 输出2/6
	cout << modulus<int>()(2, 6) << endl;	// 输出2%6
	cout << negate<int>()(2) << endl;		// 输出-2

	system("PAUSE");            			// 调用库函数system( )，输出系统提示信息
	return 0;                    			// 返回值0, 返回操作系统
}
