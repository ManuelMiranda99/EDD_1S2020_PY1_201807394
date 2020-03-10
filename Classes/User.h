//
// Created by Manuel on 7/03/2020.
//

#ifndef EDD_1S2020_PY1_201807394_USER_H
#define EDD_1S2020_PY1_201807394_USER_H

#include "fstream"

using namespace std;

class SimpleListIS {
    class NodeIS {
    public:
        int score;
        NodeIS *next;

        NodeIS(int _score) {
            score = _score;
            next = NULL;
        }
    };

public:

    NodeIS *first;
    int size;
    string user;

    SimpleListIS(string _user) {
        first = NULL;
        user = _user;
        size = 0;
    }

    void InsertScore(int _score) {
        NodeIS *newNode = new NodeIS(_score);

        if (first == NULL) {
            first = newNode;
        } else {
            NodeIS *aux1 = first;
            NodeIS *aux2;

            while ((aux1 != NULL) && (aux1->score > _score)) {
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

    void GenerateReport() {
        string graph = "digraph L { \n"
                       "rankdir=LR;";
        int x = 1;
        NodeIS *aux = this->first;
        if (aux != NULL) {
            do {
                graph += "X" + to_string(x) + " [shape=box,color=lightblue,style=filled,label=\"" +
                         to_string(aux->score) + "\"];\n";
                x++;
                aux = aux->next;
            } while (aux != NULL);
            x = 1;
            do {
                if (x == size) {
                    graph += "X" + to_string(x);
                } else {
                    graph += "X" + to_string(x) + " -> ";
                    x++;
                    aux = aux->next;
                }
            } while (aux != NULL);
            graph += "; \n }";

            ofstream writeToFile;
            writeToFile.open("ScoresByPlayer.txt", ios_base::out | ios_base::trunc);
            if (writeToFile.is_open()) {
                writeToFile << graph;
                writeToFile.close();
            }

            system("dot -Tpng ScoresByPlayer.txt -o C:/Users/Manuel/Desktop/ScoresByPlayer.png");
            system("C:/Users/Manuel/Desktop/ScoresByPlayer.png");
        }
    };

};

class DoubleList {
    class NodeIC {
    public:
        char letter;
        int points;
        NodeIC *previous, *next;

        NodeIC(char _letter) {
            letter = _letter;

            switch (letter) {
                case 'A':
                case 'E':
                case 'O':
                case 'I':
                case 'S':
                case 'N':
                case 'L':
                case 'R':
                case 'U':
                case 'T':
                    points = 1;
                    break;
                case 'D':
                case 'G':
                    points = 2;
                    break;
                case 'C':
                case 'B':
                case 'M':
                case 'P':
                    points = 3;
                    break;
                case 'H':
                case 'F':
                case 'V':
                case 'Y':
                    points = 4;
                    break;
                case 'Q':
                    points = 5;
                    break;
                case 'J':
                case ';':
                case -92:
                case 'X':
                    points = 8;
                    break;
                case 'Z':
                    points = 10;
                    break;
                default:
                    points = 0;
                    break;
            }

            previous = NULL;
            next = NULL;
        }
    };

private:
    NodeIC *first, *last;
    int size;
public:
    DoubleList() {
        first = last = NULL;
        size = 0;
    }

    void InsertNode(char _letter) {
        NodeIC *newNode = new NodeIC(_letter);

        if (first == NULL) {
                first = last= newNode;
        }else{
            last->next = newNode;
            newNode->previous = last;;

            last = newNode;
        }
        size++;
    }

    int DeleteNode(char _letter) {
        if(first != NULL){
            NodeIC *aux2, *aux = first;
            while(aux != NULL){
                if(aux->letter == _letter){
                    break;
                }else{
                    aux2 = aux;
                    aux = aux->next;
                }
            }
            if(aux != NULL){
                if(aux->next != NULL){
                    aux2->next = aux->next;
                    aux->next->previous = aux2;
                }else{
                    aux2->next = NULL;
                }
            }
            return aux->points;
        }
        return 0;
    }

    string GetCoins() {
        string text = "";
        if(first != NULL){
            NodeIC *aux = first;
            while(aux != last){
                text += aux->letter + ", ";
                aux = aux->next;
            }
            text += aux->letter;
        }
        return text;
    }

    void GenerateReport() {
        string graph = "digraph L {\n";
        int x = 1;
        NodeIC *aux = first;
        if (aux != NULL) {
            while (aux != NULL) {
                graph += "X" + to_string(x) + " [color=lightgray,style=filled, label=\"" + aux->letter + "\"];\n";
                x++;
                aux = aux->next;
            }
            graph += "nullNode [shape=none,label=\"null\"];\n";
            x = 1;
            aux = first;
            while (aux != NULL) {
                graph += "X" + to_string(x) + " -> ";
                x++;
                aux = aux->next;
            }
            x--;
            graph += " nullNode; \n";
            while (x > 1) {
                graph += "X" + to_string(x) + "->";
                x--;
            }
            graph += " X1; \n }";
            ofstream writeToFile;
            writeToFile.open("FichasIndividuales.txt", ios_base::out | ios_base::trunc);
            if (writeToFile.is_open()) {
                writeToFile << graph;
                writeToFile.close();
            }

            system("dot -Tpng FichasIndividuales.txt -o C:/Users/Manuel/Desktop/FichasIndividuales.png");
            system("C:/Users/Manuel/Desktop/FichasIndividuales.png");
        }

    };
};

class User {
    public:
        string name;
        User *left, *right;

        SimpleListIS *scores;
        DoubleList *coins;

        int points;
        User(string);
        void GetPoints(int);
        void StartGame();
        void AddCoins(char);
        bool UseCoin(char);
        string GetCoins();
        void AddScore();
        int GetMaximumScore();
        string GenerateGraphviz();
        void GenerateScoresReport();
        void GenerateCoinsReport();
};


#endif //EDD_1S2020_PY1_201807394_USER_H
