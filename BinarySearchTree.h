//
// Created by Manuel on 7/03/2020.
//

#ifndef EDD_1S2020_PY1_201807394_BINARYSEARCHTREE_H
#define EDD_1S2020_PY1_201807394_BINARYSEARCHTREE_H


#include "User.h"

class BinarySearchTree {
    public:
        User *root;
        BinarySearchTree();
        void addUser(string);
        User GetUser(string);
        void PreOrderReport();
        void InOrderReport();
        void PostOrderReport();

    private:
        void RecursiveAdd(User);
        User RecursiveGetUser(string);
        void RecursivePreOrder(User);
        void RecursiveINOrder(User);
        void RecursivePostOrder(User);
};


#endif //EDD_1S2020_PY1_201807394_BINARYSEARCHTREE_H
