//
// Created by Manuel on 7/03/2020.
//

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    root = NULL;
    size = 0;
    txt = "";
    report = new SimpleListReport();
    scoreboard = new Scoreboard();
}

void BinarySearchTree::addUser(string _name) {
    root = RecursiveAdd(root, _name);
    size++;
}

User * BinarySearchTree::GetUser(string _name) {
    return RecursiveGetUser(root, _name);
}

User * BinarySearchTree::GetUser(int _id) {
    return RecursiveGetUser(root, _id);
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
        txt += "\t" + to_string(_node->id) + " - " + _node->name + "\n";
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

User * BinarySearchTree::RecursiveGetUser(User *_node, int _id) {
    if(_node != NULL){
        if(_node->id == _id){
            return _node;
        }else{
            User *temp=RecursiveGetUser(_node->left, _id);
            if(temp==0){
                temp = RecursiveGetUser(_node->right, _id);
            }
            return temp;
        }
    }else{
        return NULL;
    }
}

void BinarySearchTree::RecursivePreOrder(User *_node) {
    if(_node != NULL){
        report->InsertNode(_node->name);
        RecursivePreOrder(_node->left);
        RecursivePreOrder(_node->right);
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
        RecursivePostOrder(_node->left);
        RecursivePostOrder(_node->right);
        report->InsertNode(_node->name);
    }
}

void BinarySearchTree::GenerateReport() {
    string graph = "digraph grafica{\n"
                   "rankdir=TB;\n"
                   "graph[bgcolor=black, label=\"Usuarios\"];\n"
                   "node [style=filled, fillcolor=lemonchiffon1];\n"
                   "edge [color=white];\n";
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
    RecursiveGenerateScoreboard(root);
    scoreboard->GenerateReport();
}

void BinarySearchTree::RecursiveGenerateScoreboard(User *_node) {
    if(_node != NULL){
        RecursiveGenerateScoreboard(_node->left);
        scoreboard->InsertUser(_node);
        RecursiveGenerateScoreboard(_node->right);
    }
}

