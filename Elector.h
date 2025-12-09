#ifndef ELECTOR_H
#define ELECTOR_H
#include <iostream>

#include "Fecha.h"
#include "Direccion.h"


using namespace std;

class Elector
{
    public:
        Elector();

        string get_rut() { return rut; }
        void set_rut(string val) { rut = val; }
        string get_nombres() { return nombres; }
        void set_nombres(string val) { nombres = val; }
        Fecha get_fechaNac() { return fechaNac; }
        void set_fechaNac(Fecha val) { fechaNac = val; }
        Direccion get_direc() { return direc; }
        void set_direc(Direccion val) { direc = val; }
        int get_habilitado() { return habilitado; }
        void set_habilitado(int val) { habilitado = val; }
        int get_vocal() { return vocal; }
        void set_vocal(int val) { vocal = val; }
        int get_numMesa() { return numMesa; }
        void set_numMesa(int val) { numMesa = val; }
        void ver();


    private:
        string rut;
        string nombres;
        Fecha fechaNac;
        Direccion direc;
        int habilitado;
        int vocal;
        int numMesa;

};

#endif // ELECTOR_H
