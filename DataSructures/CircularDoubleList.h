//
// Created by Manuel on 6/03/2020.
//

#ifndef EDD_1S2020_PY1_201807394_CIRCULARDOUBLELIST_H
#define EDD_1S2020_PY1_201807394_CIRCULARDOUBLELIST_H

#include "fstream"

using namespace std;

class CircularDoubleList {
    class WordNode{
        public:
            WordNode *next, *previous;
            string word;
            WordNode(string _word){
                word = _word;
                next = NULL;
                previous = NULL;
            }
    };
private:
    WordNode *first, *last;
    int size;
public:

    CircularDoubleList();
    void InsertNode(string);
    void GenerateReport();
    bool CheckWord(string);

};


#endif //EDD_1S2020_PY1_201807394_CIRCULARDOUBLELIST_H
