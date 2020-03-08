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
