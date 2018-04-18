//主文件：s3_9\smain3_9.cpp
#include <iostream>  
using namespace std; 

// 声明公共基类
class Furniture 
{
public:
	Furniture (float w): weight(w){}            
	void SetWeight(float w) { weight=w;}	//设置重量
	float GetWeight() const { return weight; }	//得到重量
protected:
	float weight;							//重量
};

class Bed: virtual public Furniture			//将公共基类声明为虚基类
{
public:
	Bed(float w): Furniture(w) {}			//一级派生类构造函数，负责初始化公共基类的数据成员
	void Sleep() { cout<<"开始睡觉"<<endl; }	//睡觉		
};

class Sofa: virtual public Furniture		//在定义一级派生类时必须将公共基类声明为虚基类
{
public:
	Sofa(float w): Furniture(w) {}			//一级派生类构造函数，负责初始化公共基类的数据成员
	void WatchTV() { cout<<"正在看电视"<<endl; }//看电视		
};

class SofaBed : public Sofa, public Bed  
{
public:
	SofaBed(float w): Furniture(w), Sofa(w), Bed(w) {}  //初始化3个基类的数据成员  
	void FoldOut() { cout<<"可以折叠和打开"<<endl; }	//折叠
};

int main( )
{
	SofaBed sb(50.5);
	sb.SetWeight(51.9);
	cout<<"家具重"<<sb.GetWeight()<<"千克"<<endl;
	sb.WatchTV();
	sb.FoldOut();
	sb.Sleep();

	return 0;
}
