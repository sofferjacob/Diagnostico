#ifndef FRACCION_H
#define FRACCION_H

class Fraccion {
    public:
        int getNum();
        int getDen();
        void setNum(int num);
        void setDen(int den);
        Fraccion sumFrac(Fraccion &otra);
        Fraccion multiplyFrac(Fraccion &otra);
        void printFrac();
        double toDecimal(); // Regresa la representación decimal de la fracción

        // Constructor
        Fraccion(int num = 0, int den = 1);
        Fraccion(double decimal);

    private:
        int num;
        int den;
        void simplify();
};

#endif