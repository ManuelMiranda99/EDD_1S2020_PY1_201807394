//
// Created by Manuel on 7/03/2020.
//

#include "Queue.h"

Queue::Queue() {
    first = NULL;
    last = NULL;
    size = 0;
}

void Queue::EnQueue(char _letter) {
    Coin *newCoin = new Coin(_letter);
    if(first == NULL){
        first = newCoin;
    }else{
        last->next = newCoin;
    }
    last = newCoin;
    size++;
}

char Queue::DeQueue() {
    if(first !=NULL){
        Coin *aux = first;
        char charToReturn = aux->letter;
        if(size == 1){
            last = NULL;
        }
        first = aux->next;
        delete aux;
        size--;

        return charToReturn;
    }
    return NULL;
}

void Queue::GenerateReport() {
    Coin *aux = first;
    if(aux != NULL){
        string graph = "diagraph L {\n";
        int x = 1;
        while(aux != NULL){
            graph += "X" + to_string(x) + " [shape=box, color=lightblue, style=filled, label=\"" + aux->letter + "x" + to_string(aux->points) + "\"];\n";
            x++;
            aux = aux->next;
        }
        aux = first;
        x = 1;
        while(aux != last){
            graph += "X" + to_string(x) + " -> ";
            x++;
            aux = aux->next;
        }
        graph += "X" + to_string(x) + ";\n}";

        ofstream writeToFile;
        writeToFile.open("Queue.txt", ios_base::out | ios_base::trunc);
        if(writeToFile.is_open()){
            writeToFile << graph;
            writeToFile.close();
        }

        system("dot -Tpng Queue.txt -o C:/Users/Manuel/Desktop/Queue.png");
        system("C:/Users/Manuel/Desktop/Queue.png");
    }
}
