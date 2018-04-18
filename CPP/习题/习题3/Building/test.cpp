#include "CBuilding.h"
#include <stdio.h>

int main()
{
    CHousing house;
    COfficeBuilding office;
    printf("house:\narea=%f   floorNumber=%d   roomNumber=%d   bedRoom=%d  livingRoom=%d\n",house.area,house.floorNumber,house.roomNumber,house.bedRoom,house.livingRoom);
    printf("office:\narea=%f   floorNumber=%d   roomNumber=%d   fireNum=%d  phoneNum=%d\n", office.area, office.floorNumber, office.roomNumber, office.fireNum, office.phoneNum);
    return 0;
}