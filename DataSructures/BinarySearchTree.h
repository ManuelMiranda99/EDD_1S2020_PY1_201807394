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
                       "\trankdir=LR;\n"
                       "\tgraph[bgcolor=black];\n"
                       "\tnode[shape=box, style=filled, fillcolor=lemonchiffon1];\n"
                       "\tedge[color=white];\n\n";
        int x = 1;
        NodeSL *aux = first;
        if(aux != NULL){
            do{
                graph += "X" + to_string(x) + " [label=\"" + aux->name + "\"];\n";
                x++;
                aux = aux->next;
            }while (aux != NULL);
            x = 1;
            aux = first;
            do{
                graph += "X" + to_string(x) + " -> ";
                x++;
                aux = aux->next;
            }while(aux->next != NULL);
            graph += " X" + to_string(x) + "; \n }";

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

class Scoreboard{
    class NodeSB{
        public:
            User *user;
            NodeSB *next;
            NodeSB(User *_user){
                user = _user;
                next = NULL;
            }
    };

    public:
        NodeSB *first;
        int size;
        Scoreboard(){
            first = NULL;
            size = 0;
        }

        void InsertUser(User *_user){
            NodeSB *newNode = new NodeSB(_user);
            if(newNode->user->scores->first != NULL){
                if(first == NULL){
                    first = newNode;
                }else{
                    NodeSB *aux1 = first;
                    NodeSB *aux2;

                    while ((aux1 != NULL) && (aux1->user->GetMaximumScore() > newNode->user->GetMaximumScore())) {
                        aux2 = aux1;
                        aux1 = aux1->next;
                    }

                    if (aux1 == first) {
                        first = newNode;
                    } else {
                        aux2->next = newNode;
                    }

                    newNode->next = aux1;
                }
                size++;
            }
        }

        void deleteList(){
            first = NULL;
            size = 0;
        }

        void GenerateReport(){
            string graph = "digraph L { \n"
                           "\trankdir=LR;\n"
                           "\tgraph[bgcolor=black, label=\"Scoreboard\", fontcolor=white];\n"
                           "\tnode[shape=box, style=filled, fillcolor=lemonchiffon1];\n"
                           "\tedge[color=white];\n\n";
            int x = 1;
            NodeSB *aux = first;
            if (aux != NULL) {
                do {
                    graph += "X" + to_string(x) + " [label=\"" +
                             "" + aux->user->name + " - " + to_string(aux->user->GetMaximumScore()) + "pts\"];\n";
                    x++;
                    aux = aux->next;
                } while (aux != NULL);
                aux = first;
                x = 1;
                do {
                    if (x == size) {
                        graph += "X" + to_string(x);
                    } else {
                        graph += "X" + to_string(x) + " -> ";
                        x++;
                    }
                    aux = aux->next;
                } while (aux != NULL);
                graph += "; \n }";

                ofstream writeToFile;
                writeToFile.open("Scoreboard.txt", ios_base::out | ios_base::trunc);
                if (writeToFile.is_open()) {
                    writeToFile << graph;
                    writeToFile.close();
                }

                system("dot -Tpng Scoreboard.txt -o C:/Users/Manuel/Desktop/Scoreboard.png");
                system("C:/Users/Manuel/Desktop/Scoreboard.png");
            }
        }
};

class BinarySearchTree {
    public:
        User *root;
        int size;
        string txt;
        SimpleListReport *report;
        Scoreboard *scoreboard;

        BinarySearchTree();
        void addUser(string);

        // Try to use IDs for each user. This to help the GetUser functionality
        User * GetUser(string);
        User * GetUser(int);
        void PreOrderReport();
        void InOrderReport();
        void PostOrderReport();
        void GenerateReport();
        void GenerateScoreboard();
    private:
        User * RecursiveAdd(User *, string);
        User * RecursiveGetUser(User *, string);
        User * RecursiveGetUser(User *, int);
        void RecursivePreOrder(User *);
        void RecursiveInOrder(User *);
        void RecursivePostOrder(User *);
        void RecursiveGenerateScoreboard(User *);
};


#endif //EDD_1S2020_PY1_201807394_BINARYSEARCHTREE_H
