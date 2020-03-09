//
// Created by Manuel on 8/03/2020.
//

#ifndef EDD_1S2020_PY1_201807394_MATRIX_H
#define EDD_1S2020_PY1_201807394_MATRIX_H


#include "MatrixNode.h"

class Matrix {
private:
    MatrixNode *header = new MatrixNode(0 ,0 ,0);

    MatrixNode *CreateRow();
    MatrixNode *CreateColumn();
    MatrixNode InsertOrderedRow();
    MatrixNode InsertOrderedColumn();
    MatrixNode *SearchRow();
    MatrixNode *SearchColumn();
public:
    Matrix();
    void InsertNode();
    void GenerateReport();
};


#endif //EDD_1S2020_PY1_201807394_MATRIX_H
