// �ļ�·����:a4_2\main.cpp
#include <iostream>               				// ����Ԥ��������
using namespace std;							// ʹ�������ռ�std 

// ����������
class Complex
{
private:
// ���ݳ�Ա
	double real;								// ʵ��
	double image;								// �鲿

public:
// ���к���	
	Complex(double r = 0, double i = 0): real(r), image(i){ }			// ���캯��
	double GetReal() const { return real; }		// ����ʵ��
	double GetImage() const { return image; }	// �����鲿
	void SetReal(double r) { real = r; }			// ����ʵ��
	void SetImage(double i) { image = i; }		// �����鲿
};

istream &operator>>(istream &in, Complex &z)	// �������������">>"
{
	double r, i;								// ��ʾʵ��(r)���鲿(i)
	cout << "����ʵ��:";
	in >> r;									// ����ʵ��
	cout << "�����鲿:";
	in >> i;									// �����鲿
	z.SetReal(r);								// ����ʵ��
	z.SetImage(i);								// �����鲿
	return in;									// ��������������
}

ostream &operator<<(ostream &out, const Complex &z)						// ������������"<<"
{
	if (z.GetImage() < 0) cout << z.GetReal() << z.GetImage() << "i";	// �鲿Ϊ��
	else if (z.GetImage() == 0) cout << z.GetReal();					// �鲿Ϊ0
	else cout << z.GetReal() << "+" << z.GetImage() << "i";				// �鲿Ϊ��
	return out;									// �������������
}

int main()										// ������main()
{
	Complex z;									// ���帴������
	cin >> z;									// ����z, cin >> z�ȼ���operator>>(cin, z)
	cout << z << endl;							// ���z, cout << z�ȼ���operator<<(cout, z)

	system("PAUSE");							// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;               					// ����ֵ0, ���ز���ϵͳ
}
