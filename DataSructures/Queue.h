//
// Created by Manuel on 7/03/2020.
//

#ifndef EDD_1S2020_PY1_201807394_QUEUE_H
#define EDD_1S2020_PY1_201807394_QUEUE_H

#include "fstream"

using namespace std;

class Queue {
    class Coin{
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
                    case 'J': case ';': case -92: case 'X':
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
    private:
        Coin *first, *last;
        int size;
    public:
    Queue();
    void EnQueue(char);
    char DeQueue();
    void GenerateReport();
};


#endif //EDD_1S2020_PY1_201807394_QUEUE_H
