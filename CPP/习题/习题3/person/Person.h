#include <iostream>
#include <string.h>
using namespace std;

class Person
{
public:
    string name, sex, phone, address;
    int age, salary;
    void Show();
};

class Teacher : virtual public Person
{
public:
    string zhichen;
    void Show();
};

class Cadre : virtual public Person
{
public:
    string zhiwu;
    void Show();
};

class TeacherCadre:public Teacher, public Cadre
{
public:
    void Show();
};

void Person::Show()
{
    cout << "Person" << endl;
}

void Teacher::Show()
{
    cout << endl << "Teacher" << endl;
}

void Cadre::Show()
{
    cout << endl << "Cadre!" << endl;
}

void TeacherCadre::Show()
{
    cout << endl << "TeacherCadre!" << endl;
}