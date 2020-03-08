//
// Created by Manuel on 7/03/2020.
//

#ifndef EDD_1S2020_PY1_201807394_USER_H
#define EDD_1S2020_PY1_201807394_USER_H

#include "fstream"

using namespace std;

class SimpleListIS{
    class NodeIS{
        public:
            int score;
            NodeIS *next;
            NodeIS(int _score){
                score = _score;
                next = NULL;
            }
    };
    NodeIS *first;
    int size;
    string user;
    SimpleListIS(string _user){
        first = NULL;
        user = _user;
        size = 0;
    }

    void InsertScore(int _score){
        NodeIS *newNode = new NodeIS(_score);

        if(first == NULL){
            first = newNode;
        }else{
            NodeIS *aux1 = first;
            NodeIS *aux2;

            while((aux1 != NULL) && (aux1->score > _score)){
                aux2 = aux1;
                aux1 = aux1->next;
            }

            if(aux1 == first){
                first = newNode;
            }else{
                aux2->next = newNode;
            }

            newNode->next = aux1;
        }
        size++;
    }
    void GenerateReport(){
        string graph = "digraph L { \n"
                       "rankdir=LR;";
        int x = 1;
        NodeIS *aux = this->first;
        if(aux != NULL){
            do{
                graph += "X" + to_string(x) + " [shape=box,color=lightblue,style=filled,label=\"" + to_string(aux->score) + "\"];\n";
                x++;
                aux = aux->next;
            }while (aux != NULL);
            x = 1;
            do{
                if(x == size){
                    graph += "X" + to_string(x);
                }else{
                    graph += "X" + to_string(x) + " -> ";
                    x++;
                    aux = aux->next;
                }
            }while(aux != NULL);
            graph += "; \n }";

            ofstream writeToFile;
            writeToFile.open("ScoresByPlayer.txt", ios_base::out | ios_base::trunc);
            if(writeToFile.is_open()){
                writeToFile << graph;
                writeToFile.close();
            }

            system("dot -Tpng ScoresByPlayer.txt -o C:/Users/Manuel/Desktop/ScoresByPlayer.png");
            system("C:/Users/Manuel/Desktop/ScoresByPlayer.png");
    }
};

class User {
    public:
        string name;
        User *left, *right;
        /*
         * SimpleListIS scores; Add to the constructor
         * DoubleList coins; Add to the constructor
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
