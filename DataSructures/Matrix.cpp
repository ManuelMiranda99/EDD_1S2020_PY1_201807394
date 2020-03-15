//
// Created by Manuel on 8/03/2020.
//

#include "Matrix.h"

Matrix::Matrix(int _dimension) {
    header = new MatrixNode(0 ,0 ,0);
    maxDimension = _dimension;
}

void Matrix::InsertSpecialNode(int _XCoord, int _YCoord, int _Multiplier) {
    MatrixNode *newNode = new MatrixNode(_XCoord, _YCoord, _Multiplier);
}

Coin Matrix::DeleteNode(int _xCoord, int _yCoord) {

}

void Matrix::GenerateReport() {

}

MatrixNode *Matrix::CreateRow() {
    return nullptr;
}

MatrixNode *Matrix::CreateColumn() {
    return nullptr;
}

MatrixNode Matrix::InsertOrderedRow() {
    return MatrixNode(0, 0, 0);
}

MatrixNode Matrix::InsertOrderedColumn() {
    return MatrixNode(0, 0, 0);
}

MatrixNode *Matrix::SearchRow() {
    return nullptr;
}

MatrixNode *Matrix::SearchColumn() {
    return nullptr;
}

void Matrix::PutCoin(int _XPos, int _YPos, Coin _coin) {

}
