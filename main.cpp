/*
Evaluación Diagnostica
Jacobo Soffer | A01028653
03/11/20

NOTA: Necesita compilarse con -std=c++11
*/
#include "fraccion_loop.h"
#include "matfrac.h"
#include <iostream>

using namespace std;

int main() {
    bool keepLooping = true;

    cout << "Evaluación diagnóstica\n";
    cout << "Jacobo Soffer | A01028653\n";

    MatFrac matFrac;

    while (keepLooping) {
        cout << "Selecciona una opción del menú:\n";
        cout << "1: Fracciones\n2: MatFrac\nq: Salir del programa\n";
        cout << "Selecciona una opción: ";
        string selectedOption;
        cin >> selectedOption;

        switch (selectedOption[0]) {
            case '1':
                try {
                    startFractionLoop();
                } catch (const char* msg) {
                    cout << "Ha ocurrido un error, verifica tus datos de entrada: " << msg << endl;
                } catch (...) {
                    cout << "Ha ocurrido un error, verifica tus datos de entrada." << endl;
                }
                break;
            case '2':
                //matFrac
                try {
                    matFrac.run();
                } catch (const char* msg) {
                    cout << "Ha ocurrido un error, verifica los archivos de entrada: " << msg << endl;
                } catch(...) {
                    cout << "Ha ocurrido un error, verifica los archivos de entrada\n";
                }
                break;
            case 'q':
                keepLooping = false;
                break;
            default:
                cout << "Favor de seleccionar una opción valida\n";
                break;
        }
    }
    return 0;
}