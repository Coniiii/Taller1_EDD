#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    public:
        Fecha();

        int get_dd() { return dd; }
        void set_dd(int val) { dd = val; }
        int get_mm() { return mm; }
        void set_mm(int val) { mm = val; }
        int get_aa() { return aa; }
        void set_aa(int val) { aa = val; }
        void ver();

    private:
        int dd;
        int mm;
        int aa;
};

#endif // FECHA_H
