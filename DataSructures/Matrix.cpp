//
// Created by Manuel on 8/03/2020.
//

#include "Matrix.h"

Matrix::Matrix(int _dimension) {
    header = new MatrixNode(0 ,0 ,0);
    maxDimension = _dimension;
}

void Matrix::InsertNode(int _xCoord, int _yCoord, Coin _coin) {

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
