//
// Created by Manuel on 7/03/2020.
//

#ifndef EDD_1S2020_PY1_201807394_USER_H
#define EDD_1S2020_PY1_201807394_USER_H

#include "fstream"

using namespace std;

class User {
    public:
        string name;
        User *left, *right;
        /*
         * SimpleList scores = new SimpleList();
         * DoubleList coins = new DoubleList();
         */
        int points;
        User(string);
        void GetPoints(int);
        void StartGame();
        int GetMaximumScore();
        void GenerateScoresReport();
        void GenerateCoinsReport();
};


#endif //EDD_1S2020_PY1_201807394_USER_H
