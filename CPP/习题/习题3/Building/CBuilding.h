#ifndef CBUILDING
#define CBUILDING

class CBuilding
{
public:
    int floorNumber=1;
    int roomNumber=2;
    double area=3;
};

class CHousing: public CBuilding
{
public:
    int bedRoom=4;
    int livingRoom=5;
};

class COfficeBuilding: public CBuilding
{
public:
    int fireNum=6;
    int phoneNum=7;
};
#endif //CBUILDING