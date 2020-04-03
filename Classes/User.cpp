//
// Created by Manuel on 7/03/2020.
//

#include "User.h"

User::User(string _name, int _id) {
    name = _name;
    id = _id;
    coins = new DoubleList(name);
    usedCoins = new DoubleList(name);
    scores = new SimpleListIS(name);
    left = right = NULL;
}

void User::GetPoints(int _points) {
    points += _points;
}

void User::StartGame() {
    points = 0;
    coins->EmptyList();
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

char User::GetCoinAt(int _pos) {
    return coins->DeleteNodeAt(_pos);
}

void User::AddScore() {
    scores->InsertScore(points);
}

string User::GetCoins() {
    return coins->GetCoins();
}

string User::GenerateGraphviz() {
    string graph;
    graph += "\"" + name + "\" [label=\"" + name + "\"];\n";

    if(left != NULL){
        graph += left->GenerateGraphviz() + "\"" + name + "\"->\"" + left->name + "\";\n";
    }
    if(right != NULL){
        graph += right->GenerateGraphviz() + "\"" + name + "\"->\"" + right->name + "\";\n";
    }
    graph += "\n";
    return graph;

}
