//
// Created by Manuel on 7/03/2020.
//

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    root = NULL;
    size = 0;
    report = new SimpleListReport();
    scoreboard = new Scoreboard();
}

void BinarySearchTree::addUser(string _name) {
    root = RecursiveAdd(root, _name);
    size++;
}

User BinarySearchTree::GetUser(string _name) {
    return *RecursiveGetUser(root, _name);
}

void BinarySearchTree::PreOrderReport() {
    report->deleteList();
    RecursivePreOrder(root);
    report->GenerateReport();
}

void BinarySearchTree::InOrderReport() {
    report->deleteList();
    RecursiveInOrder(root);
    report->GenerateReport();
}

void BinarySearchTree::PostOrderReport() {
    report->deleteList();
    RecursivePostOrder(root);
    report->GenerateReport();
}

User * BinarySearchTree::RecursiveAdd(User *_node, string _name) {
    if(_node == NULL){
        _node = new User(_name, size+1);
    } else if(_name < _node->name){
        _node->left = RecursiveAdd(_node->left, _name);
    }else if(_name > _node->name){
        _node->right = RecursiveAdd(_node->right, _name);
    }
    return _node;
}

User * BinarySearchTree::RecursiveGetUser(User *_node, string _name) {
    if(_node == NULL || _node->name == _name){
        return _node;
    }

    if(_node->name > _name){
        return RecursiveGetUser(_node->left, _name);
    }
    return  RecursiveGetUser(_node->right, _name);
}

void BinarySearchTree::RecursivePreOrder(User *_node) {
    if(_node != NULL){
        report->InsertNode(_node->name);
        RecursiveInOrder(_node->left);
        RecursiveInOrder(_node->right);
    }
}

void BinarySearchTree::RecursiveInOrder(User *_node) {
    if(_node != NULL){
        RecursiveInOrder(_node->left);
        report->InsertNode(_node->name);
        RecursiveInOrder(_node->right);
    }
}

void BinarySearchTree::RecursivePostOrder(User *_node) {
    if(_node != NULL){
        RecursiveInOrder(_node->left);
        RecursiveInOrder(_node->right);
        report->InsertNode(_node->name);
    }
}

void BinarySearchTree::GenerateReport() {
    string graph = "diagraph grafica{\n"
                   "rankdir=TB;\n"
                   "node [shape=record, style=filled, fillcolor=blue];\n";
    graph += root->GenerateGraphviz();
    graph += "}";

    ofstream writeToFile;
    writeToFile.open("ArbolUsuarios.txt", ios_base::out | ios_base::trunc);
    if(writeToFile.is_open()){
        writeToFile << graph;
        writeToFile.close();
    }

    system("dot -Tpng ArbolUsuarios.txt -o C:/Users/Manuel/Desktop/ArbolUsuarios.png");
    system("C:/Users/Manuel/Desktop/ArbolUsuarios.png");

}

void BinarySearchTree::GenerateScoreboard() {
    scoreboard->deleteList();
    RecursiveInOrder(root);
    scoreboard->GenerateReport();
}

void BinarySearchTree::RecursiveGenerateScoreboard(User *_node) {
    if(_node != NULL){
        RecursiveGenerateScoreboard(_node->left);
        scoreboard->InsertUser(_node);
        RecursiveGenerateScoreboard(_node->right);
    }
}
