#include "Fecha.h"

#include <iostream>

using namespace std;

Fecha::Fecha()
{
    dd = 0;
    mm = 0;
    aa = 0;
}

void Fecha::ver()
{
    //cout<<"--------------------------------------------------------------------------------------------------";
    cout << "Fecha :                     " << dd << "/" << mm << "/" << aa <<endl;
}
