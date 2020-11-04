#ifndef MATFRAC_H
#define MATFRAC_H

#include "fraccion.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class MatFrac {
    public:
        MatFrac();
        int getMatrixSize(int matrix);
        void printMat(vector<vector<Fraccion> > &mat);
        void run();

    private:
        int matSize;

        vector<vector<Fraccion> > matrix1;
        vector<vector<Fraccion> > matrix2;
        vector<vector<Fraccion> > matrix3;

        // Files
        std::ifstream file1;
        std::ifstream file2;
        std::ofstream file3;

        void populateVecs();
        void writeToFile();
        void buildMatrix();
};

#endif