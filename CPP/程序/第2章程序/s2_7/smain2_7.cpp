// �ļ�·����: s2_7\smain 2_7.cpp

class CDemo
{
public:
	CDemo()
	{
		a = 0;
	}
	CDemo(int x=1)
	{
		a = x;
	}
private:
	int a;
};

int main()
{
	CDemo d1(10);		//���ô�Ĭ�ϲ����Ĺ��캯���������ݳ�Աa��ʼ��Ϊ10
	// CDemo d2;		//�ȿ��Ե����޲ι��캯�����ֿ��Ե��ô�Ĭ�ϲ����Ĺ��캯�����������壡
	return 0;
}
