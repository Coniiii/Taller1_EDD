#include "Direccion.h"

#include <iostream>

using namespace std;

Direccion::Direccion()
{
    calle = "Sin direccion";
    num = 0;
    comuna = "Sin comuna";
}

void Direccion::ver()
{
    //cout<<"--------------------------------------------------------------------------------------------------";
    cout << "Direcion :                  " << calle << " " << num << ", "<< comuna <<endl;
}
