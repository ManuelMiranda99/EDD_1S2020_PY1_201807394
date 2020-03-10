//
// Created by Manuel on 7/03/2020.
//

#ifndef EDD_1S2020_PY1_201807394_BINARYSEARCHTREE_H
#define EDD_1S2020_PY1_201807394_BINARYSEARCHTREE_H


#include "../Classes/User.h"

class SimpleListReport{
    class NodeSL{
        public:
            NodeSL *next;
            string name;
            NodeSL(string _name){
                name = _name;
                next = NULL;
            }
    };

public:
    NodeSL *first, *last;
    int size;
    SimpleListReport(){
        first = last = NULL;
        size = 0;
    }
    void deleteList(){
        first = NULL;
        size = 0;
    }
    void InsertNode(string _name){
        NodeSL *newNode = new NodeSL(_name);
        if(first == NULL){
            first = last = newNode;
        }else{
            last->next = newNode;
            last = newNode;
        }
        size++;
    }
    void GenerateReport(){
        string graph = "digraph L { \n"
                       "rankdir=LR;";
        int x = 1;
        NodeSL *aux = first;
        if(aux != NULL){
            do{
                graph += "X" + to_string(x) + " [shape=box,color=lightblue,style=filled,label=\"" + aux->name + "\"];\n";
                x++;
                aux = aux->next;
            }while (aux != first);
            x = 1;
            do{
                graph += "X" + to_string(x) + " -> ";
                x++;
                aux = aux->next;
            }while(aux != first);
            graph += " X1; \n }";

            ofstream writeToFile;
            writeToFile.open("ReportePreInPost.txt", ios_base::out | ios_base::trunc);
            if(writeToFile.is_open()){
                writeToFile << graph;
                writeToFile.close();
            }

            system("dot -Tpng ReportePreInPost.txt -o C:/Users/Manuel/Desktop/ReportePreInPost.png");
            system("C:/Users/Manuel/Desktop/ReportePreInPost.png");
        }
    }
};

class BinarySearchTree {
    public:
        User *root;
        SimpleListReport *report;
        BinarySearchTree();
        void addUser(string);
        User GetUser(string);
        void PreOrderReport();
        void InOrderReport();
        void PostOrderReport();
        void GenerateReport();
    private:
        User * RecursiveAdd(User *, string);
        User * RecursiveGetUser(User *, string);
        void RecursivePreOrder(User *);
        void RecursiveInOrder(User *);
        void RecursivePostOrder(User *);
};


#endif //EDD_1S2020_PY1_201807394_BINARYSEARCHTREE_H
