//
// Created by Manuel on 8/03/2020.
//

#ifndef EDD_1S2020_PY1_201807394_MATRIX_H
#define EDD_1S2020_PY1_201807394_MATRIX_H


#include "MatrixNode.h"

class Matrix {
private:
    MatrixNode *header;
    int maxDimension;

    MatrixNode *CreateRow();
    MatrixNode *CreateColumn();
    MatrixNode InsertOrderedRow();
    MatrixNode InsertOrderedColumn();
    MatrixNode *SearchRow();
    MatrixNode *SearchColumn();
public:
    Matrix(int);
    void InsertNode(int, int, Coin);
    Coin DeleteNode(int, int);
    void GenerateReport();
};


#endif //EDD_1S2020_PY1_201807394_MATRIX_H
