#include <iostream>
using namespace std;

//计算任意类型数的
template <class T, class P>
T square(P x)
{
    return (T)x*x;
}

int main()
{
    double y = 3.1;
    //输出结果分别为9.61, 9,模板函数根据传输类型参数不同而返回不同值
    cout << square<float, double>(y) << endl;
    cout << square<int, double>(y) << endl;
    return 0;
}