#ifndef DIRECCION_H
#define DIRECCION_H

#include <iostream>

using namespace std;

class Direccion
{
    public:
        Direccion();

        string get_calle() { return calle; }
        void set_calle(string val) { calle = val; }
        int get_num() { return num; }
        void set_num(int val) { num = val; }
        string get_comuna() { return comuna; }
        void set_comuna(string val) { comuna = val; }
        void ver();

    private:
        string calle;
        int num;
        string comuna;
};

#endif // DIRECCION_H
