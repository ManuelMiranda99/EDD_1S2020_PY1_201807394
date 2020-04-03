//
// Created by Manuel on 8/03/2020.
//

#ifndef EDD_1S2020_PY1_201807394_COIN_H
#define EDD_1S2020_PY1_201807394_COIN_H

#include "fstream"

class Coin {
public:
    char letter;
    int points;
    Coin *next;
    Coin(char _letter){
        letter = _letter;

        switch(letter){
            case 'A': case 'E': case 'O': case 'I': case 'S':
            case 'N': case 'L': case 'R': case 'U': case 'T':
                points = 1;
                break;
            case 'D': case 'G':
                points = 2;
                break;
            case 'C': case 'B': case 'M': case 'P':
                points = 3;
                break;
            case 'H': case 'F': case 'V': case 'Y':
                points = 4;
                break;
            case 'Q':
                points = 5;
                break;
            case 'J': case ';': case 110: case 'X':
                points = 8;
                break;
            case 'Z':
                points = 10;
                break;
            default:
                points = 0;
                break;
        }

        next = NULL;
    }
};


#endif //EDD_1S2020_PY1_201807394_COIN_H
