#include "fraccion.h"
#include <iostream>

using namespace std;


Fraccion::Fraccion(int num, int den) {
    if (num < 0 || den <= 0) {
        throw "Argumentos invalidos!";
    } 
    this->num = num;
    this->den = den;
    simplify();
}

Fraccion::Fraccion(double decimal) {
    num = decimal * 100;
    den = 100;
    simplify(); 
}

int Fraccion::getNum() {
    return num;
}

int Fraccion::getDen() {
    return den;
}

void Fraccion::setNum(int num) {
    if (num < 0) {
        throw "Númerador invalido!";
    }
    this->num = num;
    simplify();
}

void Fraccion::setDen(int den) {
    if (den < 0) {
        throw "Númerador invalido!";
    }
    this->den = den;
    simplify();
}

double Fraccion::toDecimal() {
    return num /(double)den;
}

Fraccion Fraccion::sumFrac(Fraccion &otra) {
    return Fraccion(toDecimal() + otra.toDecimal());
}

Fraccion Fraccion::multiplyFrac(Fraccion &otra) {
    return Fraccion(toDecimal() * otra.toDecimal());
}

void Fraccion::printFrac() {
    cout << num << "/" << den;
}

void Fraccion::simplify() {
    bool hasMore = true;
    while (hasMore) {
        for (int i = 2; i < 11; i++) {
            if (num % i == 0 && den % i == 0) {
                num /= i;
                den /= i;
                break;
            } else if (i == 10) hasMore = false;
        }
    }
}