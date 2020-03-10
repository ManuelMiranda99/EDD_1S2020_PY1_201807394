//
// Created by Manuel on 7/03/2020.
//

#include "User.h"

User::User(string _name) {
    name = _name;
    coins = new DoubleList();
    scores = new SimpleListIS(name);
    left = right = NULL;
}

void User::GetPoints(int _points) {
    points += _points;
}

void User::StartGame() {
    points = 0;
}

int User::GetMaximumScore() {
    return scores->first->score;
}

void User::GenerateScoresReport() {
    scores->GenerateReport();
}

void User::GenerateCoinsReport() {
    coins->GenerateReport();
}

void User::AddCoins(char _letter) {
    coins->InsertNode(_letter);
}

void User::AddScore() {
    scores->InsertScore(points);
}

bool User::UseCoin(char _letter) {
    int scoreCoin = coins->DeleteNode(_letter);
    if(scoreCoin != NULL || scoreCoin != 0){
        GetPoints(scoreCoin);
        return true;
    }else{
        return false;
    }
}

string User::GetCoins() {
    return coins->GetCoins();
}

string User::GenerateGraphviz() {
    string graph;
    if(left == NULL && right == NULL){
        graph += "\"" + name + "\" [label=\"" + name + "\"];\n";
    }else{
        graph += "\"" + name + "\" [label=\"<C0>|" + name + "|<C1>\"];\n";
    }

    if(left != NULL){
        graph += left->GenerateGraphviz() + "\"" + name + "\":C0->\"" + left->name + "\";\n";
    }
    if(right != NULL){
        graph += right->GenerateGraphviz() + "\"" + name + "\":C1->\"" + right->name + "\";\n";
    }
    graph += "\n";
    return graph;

}
