#include <iostream>

#include "fraccion.h"
#include "fraccion_loop.h"

using namespace std;

bool validateString(string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

int getNumber(string output) {
    string input;
    cout << "Ingresa un " << output << ": ";
    cin >> input;
    if (!validateString(input)) {
        cout << "Número invalido, intenta de nuevo.\n";
        return getNumber(output);
    }

    int num = stoi(input);

    if (num < 0) {
        cout << "Número invalido, intenta de nuevo.\n";
        return getNumber(output);
    }
    return num;
}

Fraccion getFraction() {
    int num = getNumber("numerador");
    int den = getNumber("denominador");
    return Fraccion(num, den);
}

int startFractionLoop() {
    cout << "\nFracciones!\n";
    Fraccion fraccion = getFraction();
    Fraccion otherFrac;
    bool keepLooping = true;
    
    while (keepLooping) {
        cout << "Selecciona una opción del menu:\n";
        cout << "1: Imprimir fracción\n2: Modificar fracción\n3: Adición\n4: Multiplicación\n";
        cout << "q: Refresar al menú principal\n";
        string selectedOption;
        cout << "Seleccionar opción: ";
        cin >> selectedOption;
        cout << endl;

        switch (selectedOption[0]) {
            case '1':
                fraccion.printFrac();
                cout << endl;
                break;
            case '2':
                fraccion = getFraction();
                break;
            case '3':
                cout << "Ingresa una fracción:\n";
                otherFrac = getFraction();
                fraccion.sumFrac(otherFrac).printFrac();
                cout << endl;
                break;
            case '4':
                cout << "Ingresa una fracción:\n";
                otherFrac = getFraction();
                fraccion.multiplyFrac(otherFrac).printFrac();
                cout << endl;
                break;
            case 'q':
                keepLooping = false;
                break;
            default:
                cout << "Favor de seleccionar una opción valida.\n";
                break;
        }
    }

    return 0;
}