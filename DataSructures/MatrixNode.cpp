//
// Created by Manuel on 8/03/2020.
//

#include "MatrixNode.h"

MatrixNode::MatrixNode(int _X, int _Y, int _multiplier) {
    XCoord = _X;
    YCoord = _Y;
    multiplier = _multiplier;
    up = down = next = previous = 0;
    coin = 0;
}

MatrixNode::MatrixNode(int _X, int _Y, int _multiplier, Coin *_coin){
    XCoord = _X;
    YCoord = _Y;
    multiplier = _multiplier;
    up = down = next = previous = 0;
    coin = _coin;
}

void MatrixNode::PutCoin(Coin *_coin) {
    coin = _coin;
}

int MatrixNode::GetMultiplier() {
    return multiplier;
}