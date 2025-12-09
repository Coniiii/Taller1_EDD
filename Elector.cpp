#include "Elector.h"
#include "Fecha.h"
#include "Direccion.h"

#include <iostream>

using namespace std;

Elector::Elector()
{
    rut = "sin rut";
    nombres = "NN";
    habilitado = 0;
    vocal = 0;
    numMesa = 0;
}

void Elector::ver()
{
    cout<<endl<<"--------------------------------------------------------------------------------------------------";
    cout << endl<<"Nombre :                    " << get_nombres() << endl;
    cout << "Rut :                       " << rut << endl;

    fechaNac.ver();
    direc.ver();

    if(habilitado==1){
        cout << "Esta Habilitado para votar: Si "  <<endl;
    }
    else{
        cout << "Esta Habilitado para votar: No " <<endl;
    }
    if(vocal==1){
        cout << "Es vocal de mesa :          Si " <<endl;
    }
    else{
        cout << "Es vocal de mesa :          No " <<endl;
    }
    cout << "Numero de mesa :            " << numMesa <<endl;
    cout<<endl<<"--------------------------------------------------------------------------------------------------";
}
