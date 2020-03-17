//
// Created by Manuel on 7/03/2020.
//

#ifndef EDD_1S2020_PY1_201807394_QUEUE_H
#define EDD_1S2020_PY1_201807394_QUEUE_H

#include "fstream"
#include "../Classes/Coin.h"

using namespace std;

class Queue {
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
