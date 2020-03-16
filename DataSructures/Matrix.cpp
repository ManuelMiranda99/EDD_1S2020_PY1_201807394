//
// Created by Manuel on 8/03/2020.
//

#include "Matrix.h"

Matrix::Matrix(int _dimension) {
    header = new MatrixNode(-1, -1 ,0);
    maxDimension = _dimension;
}

void Matrix::InsertNode(int _XCoord, int _YCoord, int _Multiplier) {
    MatrixNode *newNode = new MatrixNode(_XCoord, _YCoord, _Multiplier);

    MatrixNode *column = SearchColumn(_XCoord);
    MatrixNode *row = SearchRow(_YCoord);

    // First Case
    if(column == NULL && row == NULL){
        // Create Column
        column = CreateColumn(_XCoord);

        // Create Row
        row = CreateRow(_YCoord);
    }
    // Second Case
    else if(column == NULL && row != NULL){
        // Create Column
        column = CreateColumn(_XCoord);
    }
    // Third Case
    else if(column != NULL && row == NULL){
        // Create Row
        row = CreateRow(_YCoord);
    }
    newNode = InsertOrderedColumn(newNode, row);

    newNode = InsertOrderedRow(newNode, column);
}

Coin Matrix::DeleteNode(int _xCoord, int _yCoord) {

}

void Matrix::GenerateReport() {

}

MatrixNode *Matrix::CreateRow(int _y) {
    MatrixNode *headerRow = header;
    MatrixNode *row = InsertOrderedRow(new MatrixNode(-1, _y, 0), headerRow);
    return row;
}

MatrixNode *Matrix::CreateColumn(int _x) {
    MatrixNode *headerColumn = header;
    MatrixNode *column = InsertOrderedColumn(new MatrixNode(_x, -1, 0), headerColumn);
    return column;
}

MatrixNode * Matrix::InsertOrderedRow(MatrixNode *_newNode, MatrixNode *_header_Row) {
    MatrixNode *aux = _header_Row;
    bool flag = false;

    while(true){
        if(aux->YCoord == _newNode->YCoord){
            aux->XCoord = _newNode->XCoord;
            aux->coin = _newNode->coin;
            return aux;
        }else if(aux->YCoord > _newNode->YCoord){
            flag = true;
            break;
        }

        if(aux->down != NULL){
            aux = aux->down;
        }else{
            break;
        }
    }

    if(flag){
        /*
            aux.up
            _newNode
            aux
        */
        _newNode->down = aux;
        aux->up->down = _newNode;
        _newNode->up = aux->up;
        aux->up = _newNode;
    }else{
        aux->down = _newNode;
        _newNode->up = aux;
    }
    return _newNode;
}

MatrixNode * Matrix::InsertOrderedColumn(MatrixNode *_newNode, MatrixNode *_header_Column) {
    MatrixNode *aux = _header_Column;
    bool flag = false;

    while(true){
        if(aux->XCoord == _newNode->XCoord){
            aux->YCoord = _newNode->YCoord;
            aux->coin = _newNode->coin;
            return aux;
        }else if(aux->XCoord > _newNode->XCoord){
            flag = true;
            break;
        }

        if(aux->next != NULL){
            aux = aux->next;
        }else{
            break;
        }
    }

    if(flag){
        /*
            aux.previous -><- _newNode -><- aux
        */
        _newNode->next = aux;
        aux->previous->next = _newNode;
        _newNode->previous = aux->previous;
        aux->previous = _newNode;
    }else{
        aux->next = _newNode;
        _newNode->previous = aux;
    }
    return _newNode;
}

MatrixNode *Matrix::SearchRow(int _y) {
    MatrixNode *aux = header;
    while(aux != NULL) {
        if (aux->YCoord == _y)
            return aux;
        aux = aux->down;
    }
    return NULL;
}

MatrixNode *Matrix::SearchColumn(int _x) {
    MatrixNode *aux = header;
    while(aux != NULL) {
        if (aux->XCoord == _x)
            return aux;
        aux = aux->next;
    }
    return NULL;
}

void Matrix::PutCoin(int _XPos, int _YPos, Coin _coin) {

}
