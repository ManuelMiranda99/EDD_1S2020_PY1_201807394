//
// Created by Manuel on 8/03/2020.
//

#ifndef EDD_1S2020_PY1_201807394_MATRIXNODE_H
#define EDD_1S2020_PY1_201807394_MATRIXNODE_H

#include "../Classes/Coin.h"

class MatrixNode {
public:
    MatrixNode *up, *down, *next, *previous;
    int XCoord, YCoord, multiplier;
    Coin *coin;

    // Matrix node with x and y coords. And multiplier
    MatrixNode(int, int, int);
    // Matrix node with x and y coords. Coin and multiplier
    MatrixNode(int, int, int, Coin *);
    int GetMultiplier();
    void PutCoin(Coin *);
};


#endif //EDD_1S2020_PY1_201807394_MATRIXNODE_H
