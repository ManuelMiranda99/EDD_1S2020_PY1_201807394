//
// Created by Manuel on 8/03/2020.
//

#ifndef EDD_1S2020_PY1_201807394_MATRIX_H
#define EDD_1S2020_PY1_201807394_MATRIX_H


#include "MatrixNode.h"
#include "fstream"
#include "CircularDoubleList.h"

using namespace std;

class Matrix {
private:
    MatrixNode *header;

    MatrixNode * InsertOrderedRow(MatrixNode *, MatrixNode *);
    MatrixNode * InsertOrderedColumn(MatrixNode *, MatrixNode *);
    Coin * DeleteOrderedRow(MatrixNode *, int);
    Coin * DeleteOrderedColumn(MatrixNode *, int);
    MatrixNode *SearchRow(int);
    MatrixNode *SearchColumn(int);
    MatrixNode *CreateRow(int);
    MatrixNode *CreateColumn(int);
    bool PutCoinAt(MatrixNode *, int, Coin *);
public:
    int maxDimension;

    Matrix(int);
    void InsertNode(int, int, int);
    bool PutCoin(int, int, Coin *);
    Coin * DeleteNode(int, int);
    bool CheckMatrixAt(int, int, CircularDoubleList *);
    void GenerateReport();
};


#endif //EDD_1S2020_PY1_201807394_MATRIX_H
