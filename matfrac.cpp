#include "matfrac.h"

using namespace std;

/*
Formato del archivo:
1 MAT_SIZE=s  # tamaño de la matriz
2 num         # numerador fraccion uno
3 den         # denominador fraccion uno
4 num
...
n num
n+1 den        
*/

MatFrac::MatFrac() {}

void MatFrac::run() {
    // Reset the instance
    matrix1.clear();
    matrix2.clear();
    matrix3.clear();

    string filename1;
    string filename2;
    string filename3;

    cout << "Ingresa el nombre del archivo para leer la primera matriz: ";
    cin >> filename1;
    cout << endl;

    cout << "Ingresa el nombre del archivo para leer la segunda matriz: ";
    cin >> filename2;
    cout << endl;

    cout << "Ingresa el nombre del archivo para escribir el resultado: ";
    cin >> filename3;
    cout << endl;

    file1 = ifstream(filename1);
    file2 = ifstream(filename2);

    if (!file1.good() || !file2.good()) {
        file1.close();
        file2.close();
        file3.close();
        throw "Archivo no encontrado";
    }

    file3 = ofstream(filename3);

    // Get the sizes
    string matrix1SizeStr;
    string matrix2SizeStr;

    getline(file1, matrix1SizeStr);
    getline(file2, matrix2SizeStr);

    if (matrix1SizeStr != matrix2SizeStr)
    {
        file1.close();
        file2.close();
        file3.close();
        throw "La operación de matrices no es posible";
    }

    matSize = matrix1SizeStr[matrix1SizeStr.length() - 1] - 48;

    populateVecs();
    buildMatrix();
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matSize; j++) {
            matrix3[i][j] = matrix1.at(i).at(j).sumFrac(matrix2.at(i).at(j));
        }
    }
    writeToFile();
    printMat(matrix3);
    cout << "\nEl resultado fue escrito a: " << filename3 << "\n";
}

void MatFrac::buildMatrix() {
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matSize; j++) {
            string num1;
            string den1;
            string num2;
            string den2;
            getline(file1, num1);
            getline(file1, den1);
            getline(file2, num2);
            getline(file2, den2);

            if (i == 0 && j == 1) {
                cout << "num: " << num1 << " | den: " << den1 << '\n';
            }

            matrix1[i][j].setNum(stoi(num1));
            matrix1[i][j].setDen(stoi(den1));

            matrix2[i][j].setNum(stoi(num2));
            matrix2[i][j].setDen(stoi(den2));
        }
    }
    file1.close();
    file2.close();
}

void MatFrac::printMat(vector<vector<Fraccion> > &mat) {
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matSize; j++) {
            mat[i][j].printFrac();
            cout << " ";
        }
        cout << endl;
    }
}

void MatFrac::populateVecs() {
    for (int i = 0; i < matSize; i++) {
        matrix1.push_back(vector<Fraccion>());
        matrix2.push_back(vector<Fraccion>());
        matrix3.push_back(vector<Fraccion>());
        for (int j = 0; j < matSize; j++) {
            matrix1.at(i).push_back(Fraccion());
            matrix2.at(i).push_back(Fraccion());
            matrix3.at(i).push_back(Fraccion());
        }
    }
}

void MatFrac::writeToFile() {
    file3 << "MAT_SIZE=" << matSize << endl;
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matSize; j++) {
            file3 << matrix3[i][j].getNum() << endl;
            file3 << matrix3[i][j].getDen() << endl;
        }
    }
    file3.close();
}