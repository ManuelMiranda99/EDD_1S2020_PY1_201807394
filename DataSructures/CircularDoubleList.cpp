//
// Created by Manuel on 6/03/2020.
//

#include "CircularDoubleList.h"

// Constructor
CircularDoubleList::CircularDoubleList() { first = NULL; last = NULL; size = 0;}

void CircularDoubleList::InsertNode(string _newWord) {
    string wordToInsert;

    for (char i : _newWord) {
        if(i==-61){
            wordToInsert += 'n';
        }else if(i!=-79) {
            wordToInsert += tolower(i);
        }
    }

    WordNode *newNode = new WordNode(wordToInsert);

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
        string graph = "digraph L{\n"
                       "graph[bgcolor=black];\n"
                       "node[shape=box, style=filled, fillcolor=lemonchiffon1]; \n"
                       "edge[color=white];\n\n";
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
            if(x==1){
                graph += "X1->X2 [constraint=false, dir=both];\n";
            }else{
                graph += "X" + to_string(x) + "->";
            }
            x++;
            aux = aux->next;
        }while(aux != last);
        graph += "X" + to_string(x) + "->X1 [dir=both]; \n";

        graph += "\n }";
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
    string wordToCompare;

    for (char i : _word) {
        wordToCompare += tolower(i);
    }

    if(first != NULL){
        WordNode *aux = first;
        do{
            if(aux->word == wordToCompare){
                existingWord = true;
                break;
            }
            aux = aux->next;
        }while(aux != first);
    }

    return existingWord;
}