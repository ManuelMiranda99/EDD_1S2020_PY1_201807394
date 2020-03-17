//
// Created by Manuel on 6/03/2020.
//

#include "CircularDoubleList.h"

// Constructor
CircularDoubleList::CircularDoubleList() { first = NULL; last = NULL; size = 0;}

void CircularDoubleList::InsertNode(string _newWord) {
    WordNode *newNode = new WordNode(_newWord);

    if(first == NULL){
        first = newNode;
        last = newNode;
        first->previous = last;
        last->next = first;
    }else{
        last->next = newNode;
        newNode->previous = last;

        last = newNode;

        first->previous = last;
        last->next = first;
    }
    size++;
}

void CircularDoubleList::GenerateReport() {
    if(first != NULL){
        string graph = "digraph L{\n";
        int x = 1;
        WordNode *aux = first;

        // Generating Nodes
        do{
            graph += "X" + to_string(x) + " [color=lightgray,style=filled, label=\"" + aux->word + "\"]; \n";
            x++;
            aux = aux->next;
        }while(aux != first);

        // Making connections
        x = 1;
        aux = first;
        do{
            graph += "X" + to_string(x) + "->";
            x++;
            aux = aux->next;
        }while(aux != last);
        graph += "X" + to_string(x) + "->X1; \n";

        string auxX = to_string(x);
        while(x > 1){
            graph += "X" + to_string(x) + "->";
            x--;
        }
        graph += "X1->X" + auxX + "; \n }";
        ofstream writeToFile;
        writeToFile.open("Diccionario.txt", ios_base::out | ios_base::trunc);
        if(writeToFile.is_open()){
            writeToFile << graph;
            writeToFile.close();
        }

        system("dot -Tpng Diccionario.txt -o C:/Users/Manuel/Desktop/Diccionario.png");
        system("C:/Users/Manuel/Desktop/Diccionario.png");
    }
}

bool CircularDoubleList::CheckWord(string _word) {
    bool existingWord = false;

    if(first != NULL){
        WordNode *aux = first;

        do{
            if(aux->word == _word){
                existingWord = true;
                break;
            }
        }while(aux != first);
    }

    return existingWord;
}