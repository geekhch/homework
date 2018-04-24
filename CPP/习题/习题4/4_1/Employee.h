#include <iostream>
using namespace std;

class CEmployee
{
public:
	int m_salary;
	
public:
	CEmployee():m_salary(2000){;}
	virtual void Salary() const;
};	

class CSalesman:public CEmployee
{
public:
	int sellprize = 200;

public:

	void Salary() const;
};

class CDeskman: public CEmployee
{
public:
	int workPrize = 300;

public:
	void Salary();
};

class CBuyer:public CEmployee
{
public:
	int buyPrize = 500;

public:
	void Salary();
};

void CEmployee::Salary() const
{
	cout << "Employee:" << m_salary << endl;
}

void CSalesman::Salary() const
{
	cout << "CSalesMan:" << m_salary + sellprize << endl;
}

void CDeskman::Salary()
{
	cout << "CDeskman:" << m_salary + workPrize << endl;
}

void CBuyer::Salary()
{
	cout << "CBuyer:" << m_salary + buyPrize << endl;
}