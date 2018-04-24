#include <iostream>
#include "Employee.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void getSalary(CEmployee & person) 
{
	person.Salary();
}

int main(int argc, char** argv) {
	CEmployee employee;
	CSalesman saleman;
	CDeskman desk;
	CBuyer buyer;
	getSalary(employee);
	getSalary(saleman);
	getSalary(desk);
	getSalary(buyer);
	return 0;
}