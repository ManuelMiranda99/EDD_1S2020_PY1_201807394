//
// Created by Manuel on 8/03/2020.
//

#include "MatrixNode.h"

MatrixNode::MatrixNode(int _X, int _Y, int _multiplier) {
    XCoord = _X;
    YCoord = _Y;
    multiplier = _multiplier;
    up = down = next = previous = 0;
}

int MatrixNode::GetMultiplier() {
    return multiplier;
}

void MatrixNode::PutCoin(Coin *_coin) {
    coin = _coin;
}

