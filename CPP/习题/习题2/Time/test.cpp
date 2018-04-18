#include "Time.h"
#include <stdlib.h>
using namespace std;

int main()
{
    Time t1;
    Time t2(23,54,11);
    t1.printTime();
    t2.printTime();
    system("pause");
    return 0;
}