#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "DataSructures/CircularDoubleList.h"
#include "DataSructures/BinarySearchTree.h"
#include "DataSructures/Matrix.h"
#include "Library/json.hpp"
#include "DataSructures/Queue.h"

using json = nlohmann::json;

class BagOfCoins{
    class NodeB{
        public:
            char c;
            NodeB *next;
            NodeB(char _c){
                c = _c;
                next = NULL;
            }

    };
public:
    NodeB *first, *last;
    int size;
    BagOfCoins(){
        first = last = NULL;
        size = 0;
    }

    void FillBag(){
        // Empty the list
        first = last = NULL;

        int selectedInsert = rand() % 5 + 1;

        switch (selectedInsert){
            case 1:
                InsertNode('A', 12);
                InsertNode('E', 12);
                InsertNode('O', 9);
                InsertNode('I', 6);
                InsertNode('S', 6);
                InsertNode('N', 5);
                InsertNode('L', 4);
                InsertNode('R', 5);
                InsertNode('U', 5);
                InsertNode('T', 4);
                InsertNode('D', 5);
                InsertNode('G', 2);
                InsertNode('C', 4);
                InsertNode('B', 2);
                InsertNode('M', 2);
                InsertNode('P', 2);
                InsertNode('H', 2);
                InsertNode('F', 1);
                InsertNode('V', 1);
                InsertNode('Y', 1);
                InsertNode('Q', 1);
                InsertNode('J', 1);
                InsertNode(110, 1);
                InsertNode('X', 1);
                InsertNode('Z', 1);
                break;
            case 2:
                InsertNode('Z', 1);
                InsertNode('X', 1);
                InsertNode(110, 1);
                InsertNode('J', 1);
                InsertNode('Q', 1);
                InsertNode('Y', 1);
                InsertNode('V', 1);
                InsertNode('F', 1);
                InsertNode('H', 2);
                InsertNode('P', 2);
                InsertNode('M', 2);
                InsertNode('B', 2);
                InsertNode('C', 4);
                InsertNode('G', 2);
                InsertNode('D', 5);
                InsertNode('T', 4);
                InsertNode('U', 5);
                InsertNode('R', 5);
                InsertNode('L', 4);
                InsertNode('N', 5);
                InsertNode('S', 6);
                InsertNode('I', 6);
                InsertNode('O', 9);
                InsertNode('E', 12);
                InsertNode('A', 12);
                break;
            case 3:
                InsertNode('U', 5);
                InsertNode('M', 2);
                InsertNode('I', 6);
                InsertNode('G', 2);
                InsertNode('T', 4);
                InsertNode('J', 1);
                InsertNode('E', 12);
                InsertNode(110, 1);
                InsertNode('H', 2);
                InsertNode('O', 9);
                InsertNode('R', 5);
                InsertNode('C', 4);
                InsertNode('S', 6);
                InsertNode('D', 5);
                InsertNode('F', 1);
                InsertNode('X', 1);
                InsertNode('B', 2);
                InsertNode('Z', 1);
                InsertNode('V', 1);
                InsertNode('N', 5);
                InsertNode('Q', 1);
                InsertNode('P', 2);
                InsertNode('Y', 1);
                InsertNode('L', 4);
                InsertNode('A', 12);
                break;
            case 4:
                InsertNode('T', 4);
                InsertNode('N', 5);
                InsertNode('B', 2);
                InsertNode('G', 2);
                InsertNode('S', 6);
                InsertNode('U', 5);
                InsertNode('V', 1);
                InsertNode('Y', 1);
                InsertNode(110, 1);
                InsertNode('H', 2);
                InsertNode('A', 12);
                InsertNode('I', 6);
                InsertNode('L', 4);
                InsertNode('P', 2);
                InsertNode('J', 1);
                InsertNode('F', 1);
                InsertNode('C', 4);
                InsertNode('E', 12);
                InsertNode('R', 5);
                InsertNode('M', 2);
                InsertNode('O', 9);
                InsertNode('D', 5);
                InsertNode('Z', 1);
                InsertNode('X', 1);
                InsertNode('Q', 1);
                break;
            case 5:
                InsertNode('Y', 1);
                InsertNode('P', 2);
                InsertNode('L', 4);
                InsertNode('C', 4);
                InsertNode('X', 1);
                InsertNode('N', 5);
                InsertNode('A', 12);
                InsertNode('H', 2);
                InsertNode('B', 2);
                InsertNode('M', 2);
                InsertNode('U', 5);
                InsertNode('I', 6);
                InsertNode('Q', 1);
                InsertNode('S', 6);
                InsertNode('D', 5);
                InsertNode('O', 9);
                InsertNode('Z', 1);
                InsertNode(110, 1);
                InsertNode('F', 1);
                InsertNode('G', 2);
                InsertNode('T', 4);
                InsertNode('J', 1);
                InsertNode('V', 1);
                InsertNode('E', 12);
                InsertNode('R', 5);
                break;
            default:
                InsertNode('H', 2);
                InsertNode('D', 5);
                InsertNode('R', 5);
                InsertNode('T', 4);
                InsertNode('M', 2);
                InsertNode('N', 5);
                InsertNode('V', 1);
                InsertNode('E', 12);
                InsertNode('O', 9);
                InsertNode('G', 2);
                InsertNode('L', 4);
                InsertNode('Z', 1);
                InsertNode('Y', 1);
                InsertNode('C', 4);
                InsertNode('F', 1);
                InsertNode('U', 5);
                InsertNode('B', 2);
                InsertNode('S', 6);
                InsertNode('Q', 1);
                InsertNode(110, 1);
                InsertNode('A', 12);
                InsertNode('J', 1);
                InsertNode('X', 1);
                InsertNode('I', 6);
                InsertNode('P', 2);
                break;
        }
    }

    void InsertNode(char _c, int _repeat){
        for(int i = 0; i < _repeat; i++){
            RepeatInsertNode(_c);
        }
    }

    void RepeatInsertNode(char _c){
        if(first == NULL){
            first = last = new NodeB(_c);
        }else{
            last->next = new NodeB(_c);
            last = last->next;
        }
        size++;
    }

    char DeleteNodeAt(int _pos){
        NodeB *aux = first;
        NodeB *aux2 = NULL;

        for (int i = 0; i < _pos; ++i) {
            aux2 = aux;
            aux = aux->next;
        }

        if(aux2 == NULL){
            first = aux->next;
        }
        else{
            /*
                       aux ->
               aux2      ->      aux.next
            */

            aux2->next = aux->next;

        }

        char returnChar = aux->c;
        delete(aux);
        size--;
        return returnChar;
    }

    void EmptyBag(){
        first = NULL;
        size = 0;
    }
};

class NodePos{
public:
    int x, y;
    NodePos *next;
    NodePos(int _x, int _y){
        x = _x;
        y = _y;
        next = NULL;
    }
};

class Positions{


public:
    NodePos *first;
    int size;
    Positions(){
        first = NULL;
        size = 0;
    }

    void EmptyList(){
        first = NULL;
        size = 0;
    }

    void InsertNode(int _x, int _y){
        NodePos *newNode = new NodePos(_x, _y);
        if(first == NULL){
            first = newNode;
        }else{
            newNode->next = first;
            first = newNode;
        }
        size++;
    }

    NodePos * DeleteNode(){
        NodePos *returnNode = first;
        if(size == 1){
            first = NULL;
        }else{
            first = first->next;
        }
        size--;
        return returnNode;
    }
};

class Logic{
private:
    // Data Structures
    // Dictionary of words
    CircularDoubleList *dictionary = new CircularDoubleList();
    // Binary Search Tree of users
    BinarySearchTree *users = new BinarySearchTree();
    // Coins in the game
    Queue *coins = new Queue();
    // Table of the game
    Matrix *table;
    // Users playing. actualPlayer change when a player put a coin
    User *player1, *player2, *actualPlayer;
    // General bag of coins
    BagOfCoins *bag = new BagOfCoins();
    // Auxiliar bag of coins for the coins that the user put in the table
    BagOfCoins *auxBag = new BagOfCoins();

public:
    void Move(int, int);

    // Read file with JSON library
    void ReadFile();

    // Menus used in the project
    void GeneralMenu();
    void GameMenu();
    void ReportsMenu();
    void MenuUsersReport();

    // Options of the play menu and reports
    void Play();
    void StartGame();
    bool ExitStartGame();
    void PrintTable();
    void PassTurn();

    // Create User
    void CreateUser();

    // Select user for Reports
    User * SelectUser();
};

int main() {
    Logic *logic = new Logic();
    logic->GeneralMenu();
    return 0;
}

// Function to move the cursor
void Logic::Move(int _x, int _y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = _x;
    coord.Y = _y;
    SetConsoleCursorPosition(hCon, coord);
}

void Logic::ReadFile() {
    string route;
    printf("Ingrese ruta del archivo JSON: C:/Users/Manuel/Desktop/");
    cin >> route;

    ifstream i("C:/Users/Manuel/Desktop/" + route);
    json j;
    i >> j;

    // Read File
    // Dimension of the table
    int dimension = j.at("dimension");
    table = new Matrix(dimension);

    // Special cells
    // Doubles
    for(int i = 0; i < j.at("casillas").at("dobles").size(); i++){
        int x = j.at("casillas").at("dobles")[i].at("x");
        int y = j.at("casillas").at("dobles")[i].at("y");
        table->InsertNode(x, y, 2);
    }

    // Triples
    for(int i = 0; i < j.at("casillas").at("triples").size(); i++){
        int x = j.at("casillas").at("triples")[i].at("x");
        int y = j.at("casillas").at("triples")[i].at("y");
        table->InsertNode(x, y, 3);
    }

    // Dictionary
    for(int i = 0; i < j.at("diccionario").size(); i++){
        dictionary->InsertNode(j.at("diccionario")[i].at("palabra"));
    }

}

void Logic::GameMenu() {

    bool bMenu = true;
    int sOpt = 1, sKey;
    do{
        Move(0,2);
        printf("\n\t\t\t\t MENU DE JUEGO \n");
        printf("    \t1. Crear Jugadores \n    \t2. Iniciar Partida \n    \t3. Regresar \n");
        Move(0, 3 + sOpt); printf("--->");

        do{
            sKey = getch();
            if(sKey == -32){
                sKey = getch();
            }
        }while(sKey != 72 && sKey != 80 && sKey != 13);

        switch(sKey){
            case 72:
                sOpt--;
                if(sOpt < 1){
                    sOpt = 3;
                }
                break;
            case 80:
                sOpt++;
                if(sOpt > 3){
                    sOpt = 1;
                }
                break;
            case 13:
                bMenu = false;
                break;
        }
    }while(bMenu);

    system("cls");
    switch(sOpt){
        case 1:
            // Create Players
            CreateUser();
            break;
        case 2:
            if(table != NULL){
                // Play
                player1 = player2 = NULL;
                StartGame();
            }
            else{
                system("cls");
                Move(1, 2);
                printf("No ha ingresado un archivo de entrada para jugar");
                Sleep(1000);
                system("cls");
                GameMenu();
            }
            break;
        case 3:
            // Going back
            system("cls");
            GeneralMenu();
            break;
        default:
            printf("Valor incorrecto, intente de nuevo \n\n");
            Sleep(3000);
            system("cls");
            GeneralMenu();
            break;
    }

}

void Logic::ReportsMenu() {

    bool bMenu = true;
    int sOpt = 1, sKey;
    do{
        Move(0,2);
        printf("\n\t\t\t\t MENU DE REPORTES \n");
        printf("    \t1. Reporte de Diccionario \n    \t2. Reporte de Usuarios \n    \t3. Reporte de puntajes por jugador \n    \t4. Scoreboard \n    \t5. Regresar");
        Move(0, 3 + sOpt); printf("--->");

        do{
            sKey = getch();
            if(sKey == -32){
                sKey = getch();
            }
        }while(sKey != 72 && sKey != 80 && sKey != 13);

        switch(sKey){
            case 72:
                sOpt--;
                if(sOpt < 1){
                    sOpt = 5;
                }
                break;
            case 80:
                sOpt++;
                if(sOpt > 5){
                    sOpt = 1;
                }
                break;
            case 13:
                bMenu = false;
                break;
        }
    }while(bMenu);

    system("cls");
    switch(sOpt){
        case 1:
            // Dictionary
            dictionary->GenerateReport();
            ReportsMenu();
            break;
        case 2:
            // Users
            MenuUsersReport();
            break;
        case 4:
            // Scoreboard
            users->GenerateScoreboard();
            ReportsMenu();
            break;
        case 5:
            // Going back
            system("cls");
            GeneralMenu();
            break;
        default:
            printf("Valor incorrecto, intente de nuevo \n\n");
            Sleep(3000);
            system("cls");
            GeneralMenu();
            break;
        case 3:
            // Points by player
            system("cls");
            User *reportPlayer = SelectUser();
            if(reportPlayer != NULL)
                reportPlayer->GenerateScoresReport();
            ReportsMenu();
            break;
    }

}

void Logic::MenuUsersReport() {
    bool bMenu = true;
    int sOpt = 1, sKey;
    do{
        Move(0,2);
        printf("\n\t\t\t\t MENU DE REPORTES DE USUARIOS \n");
        printf("    \t1. Arbol binario \n    \t2. Recorrido PreOrden \n    \t3. Recorrido InOrden \n    \t4. Recorrido PostOrden \n    \t5. Regresar");
        Move(0, 3 + sOpt); printf("--->");

        do{
            sKey = getch();
            if(sKey == -32){
                sKey = getch();
            }
        }while(sKey != 72 && sKey != 80 && sKey != 13);

        switch(sKey){
            case 72:
                sOpt--;
                if(sOpt < 1){
                    sOpt = 5;
                }
                break;
            case 80:
                sOpt++;
                if(sOpt > 5){
                    sOpt = 1;
                }
                break;
            case 13:
                bMenu = false;
                break;
        }
    }while(bMenu);

    system("cls");
    switch(sOpt){
        case 1:
            users->GenerateReport();
            MenuUsersReport();
            break;
        case 2:
            users->PreOrderReport();
            MenuUsersReport();
            break;
        case 3:
            users->InOrderReport();
            MenuUsersReport();
            break;
        case 4:
            users->PostOrderReport();
            MenuUsersReport();
            break;
        case 5:
            ReportsMenu();
            break;
        default:
            printf("Valor incorrecto, intente de nuevo \n\n");
            Sleep(3000);
            system("cls");
            GeneralMenu();
            break;
    }
}

// General menu with the principals options
void Logic::GeneralMenu() {
    printf( "\n UNIVERSIDAD DE SAN CARLOS DE GUATEMALA \n "
            "FACULTAD DE INGENIERIA \n "
            "ESTRUCTURAS DE DATOS \n "
            "PROYECTO 1 \n "
            "ANGEL MANUEL MIRANDA ASTURIAS \n "
            "201807394 \n\n");
    bool bMenu = true;
    int sOpt = 1, sKey;
    do{
        Move(0,6);
        printf("\n\t\t\t\t MENU \n");
        printf("    \t1. Lectura de archivo \n    \t2. Jugar \n    \t3. Reportes \n    \t4. Salir");
        Move(0, 7 + sOpt); printf("--->");

        do{
            sKey = getch();
            if(sKey == -32){
                sKey = getch();
            }
        }while(sKey != 72 && sKey != 80 && sKey != 13);

        switch(sKey){
            case 72:
                sOpt--;
                if(sOpt < 1){
                    sOpt = 4;
                }
                break;
            case 80:
                sOpt++;
                if(sOpt > 4){
                    sOpt = 1;
                }
                break;
            case 13:
                bMenu = false;
                break;
        }

    }while(bMenu);

    system("cls");
    switch(sOpt){
        case 1:
            // Read File
            ReadFile();
            printf("Archivo leido con exito");
            Sleep(1000);
            system("cls");
            GeneralMenu();
            break;
        case 2:
            // Game
            GameMenu();
            break;
        case 3:
            // Reports
            ReportsMenu();
            break;
        case 4:
            printf("Saliendo del programa... \n");
            Sleep(2000);
            break;
        default:
            printf("Valor incorrecto, intente de nuevo \n\n");
            Sleep(3000);
            system("cls");
            GeneralMenu();
            break;
    }
}

// Select user for reports. Used in "Reporte de puntajes por jugador"
User * Logic::SelectUser() {
    bool bUser = true;
    int sOpt = 1, sKey;

    do{
        system("cls");
        Move(0, 2);
        printf("\n\t\t\t\t SELECCIONA UN JUGADOR O SALGA \n");
        cout << users->txt + "\t" + to_string(users->size + 1) + " - Salir";
        for(int i = 3; i < users->size + 5; i++){
            Move(0, i);
            printf("    ");
        }
        Move(0, 3 + sOpt); printf("--->");

        do{
            sKey = getch();
            if(sKey == -32){
                sKey = getch();
            }
        }while(sKey != 72 && sKey != 80 && sKey != 13);

        switch(sKey){
            case 72:
                sOpt--;
                if(sOpt < 1){
                    sOpt = users->size + 1;
                }
                break;
            case 80:
                sOpt++;
                if(sOpt > users->size + 1){
                    sOpt = 1;
                }
                break;
            case 13:
                bUser = false;
                break;
        }
    }while(bUser);

    system("cls");

    if(sOpt == (users->size + 1)){
        return NULL;
    }
    else{
        User *selectedUser = users->GetUser(sOpt);
        return selectedUser;
    }
}

// Play
void Logic::Play() {
    Move(1, 0);
    cout << "\n\n\t\tDandole sus fichas a los jugadores... ... ..." << endl;
    Sleep(500);
    for (int i = 0; i < 7; ++i) {
        player1->AddCoins(coins->DeQueue());
    }
    Sleep(500);
    for (int i = 0; i < 7; ++i) {
        player2->AddCoins(coins->DeQueue());
    }

    // Print the table in the console
    PrintTable();

    // Randomly starting player.
    int randomPlayer = rand() % 10 + 1;
    if(randomPlayer < 5){
        actualPlayer = player1;
    }
    else{
        actualPlayer = player2;
    }

    /* -------- Variables to use during the playing loop -------- */
        // This keeps the loop running
    bool playing = true;
        // For the selection of the coin
    int coinAt = 0;
        // To insert in the matrix and to eliminate from the list of the player
    char charToInsert;
        // To save the first place where a person puts a word
    int xFinal = -1, yFinal = -1;
        // To limitate the movement of the playey
    bool UtoD = false, LtoR = false;
        // To save the positions in which the player insert a coin
    Positions *auxPositions = new Positions();
        // To save all the positions where the player put a coin. This to empy the list
    Positions *totalPositions = new Positions();

    // Initializing the messages that the program will show
    Move(0, table->maxDimension + 6);
    cout << " Jugador actual: " << actualPlayer->name << "       Puntos: " << to_string(actualPlayer->points) << endl;
    cout << " Fichas: " << actualPlayer->GetCoins() << endl;
    Move(9 + (2*coinAt), table->maxDimension + 8);

    cout << "^";

    // While they are playing
    while(playing){

        if(kbhit()){
            char key = getch();
            // Move through the Coins of the player
            if(key == -32){
                key = getch();
                switch(key){
                    // Left
                    case 75:
                        if(coinAt != 0){
                            coinAt--;
                            Move(0, table->maxDimension + 8);
                            cout << "                                         ";
                            Move(9 + (2*coinAt), table->maxDimension + 8);
                            cout << "^";
                        }
                        break;
                    // Right
                    case 77:
                        if(coinAt != actualPlayer->coins->size - 1){
                            coinAt++;
                            Move(0, table->maxDimension + 8);
                            cout << "                                         ";
                            Move(9 + (2*coinAt), table->maxDimension + 8);
                            cout << "^";
                        }
                        break;
                }
            }
            else{
                // Select coin. Select the position of the matrix where you want to put the coin
                if(key == 13){
                    charToInsert = actualPlayer->GetCoinAt(coinAt);
                    // Positions of the Matrix
                    int x = 0, y = 0;
                    if(xFinal != -1 && yFinal != -1){
                        x = xFinal;
                        y = yFinal;
                    }

                    Move(6 + (3*x),y+3);
                    // Boolean variable that will be false until they decide the place where they want to put the coin
                    bool putCoin = false;
                    while(!putCoin){
                        do{
                            key = getch();
                            if(key == -32){
                                key = getch();
                            }
                        }
                        // While the pressing key is different from Enter, Left, Right, Up, Down
                        while(key != 72 && key != 80 && key != 13 && key != 75 && key != 77);

                        switch(key){
                            // Up
                            case 72:
                                if(xFinal != -1 && yFinal != -1){
                                    if(!UtoD && !LtoR){
                                        if(x == xFinal && y != 0){
                                            y--;
                                            Move(6 + (3*x), y+3);
                                        }
                                    }else if(UtoD){
                                        if(x == xFinal && y != 0){
                                            y--;
                                            Move(6 + (3*x), y+3);
                                        }
                                    }
                                }else{
                                    if(y != 0){
                                        y--;
                                        Move(6 + (3*x), y+3);
                                    }
                                }
                                break;
                            // Down
                            case 80:
                                if(xFinal != -1 && yFinal != -1){
                                    if(!UtoD && !LtoR){
                                        if(x == xFinal && y != table->maxDimension - 1){
                                            y++;
                                            Move(6 + (3*x), y+3);
                                        }
                                    }else if(UtoD){
                                        if(x == xFinal && y != table->maxDimension - 1){
                                            y++;
                                            Move(6 + (3*x), y+3);
                                        }
                                    }
                                }else{
                                    if(y != table->maxDimension - 1){
                                        y++;
                                        Move(6 + (3*x), y+3);
                                    }
                                }
                                break;
                            // Left
                            case 75:
                                if(xFinal != -1 && yFinal != -1){
                                    if(!UtoD && !LtoR){
                                        if(y == yFinal && x != 0){
                                            x--;
                                            Move(6 + (3*x),y+3);
                                        }
                                    }else if(LtoR){
                                        if(y == yFinal && x != 0){
                                            x--;
                                            Move(6 + (3*x),y+3);
                                        }
                                    }
                                }else{
                                    if(x != 0){
                                        x--;
                                        Move(6 + (3*x),y+3);
                                    }
                                }
                                break;
                            // Right
                            case 77:
                                if(xFinal != -1 && yFinal != -1){
                                    if(!UtoD && !LtoR){
                                        if(y == yFinal && x != table->maxDimension - 1){
                                            x++;
                                            Move(6 + (3*x),y+3);
                                        }
                                    }else if(LtoR){
                                        if(y == yFinal && x != table->maxDimension - 1){
                                            x++;
                                            Move(6 + (3*x),y+3);
                                        }
                                    }
                                }else{
                                    if(x != table->maxDimension - 1){
                                        x++;
                                        Move(6 + (3*x),y+3);
                                    }
                                }
                                break;
                            // Enter. They decided the position of the coin
                            case 13:
                                putCoin = true;
                                break;
                        }
                    }

                    // If the position is not occupied
                    if(table->PutCoin(x, y, new Coin(charToInsert))){
                        cout << charToInsert;

                        if(xFinal == -1 && yFinal == -1){
                            delete(auxPositions);
                            auxPositions = new Positions();
                            xFinal = x;
                            yFinal = y;
                        }
                        if(x != xFinal){
                            LtoR = true;
                        }else if(y != yFinal){
                            UtoD = true;
                        }

                        auxPositions->InsertNode(x, y);
                        totalPositions->InsertNode(x, y);

                        auxBag->RepeatInsertNode(charToInsert);

                        table->GenerateReport();

                    }
                    else{
                        Move(0, table->maxDimension + 6);
                        cout << "                                                                                 " << endl;
                        Move(0, table->maxDimension + 6);
                        cout << "Posicion invalida";
                        Sleep(1000);
                        actualPlayer->AddCoins(charToInsert);
                    }

                    coinAt = 0;

                    Move(0, table->maxDimension + 6);
                    cout << "                                                                                         " << endl << "                                                                                         " << endl <<  "                                                                                         " ;
                    Move(0, table->maxDimension + 6);
                    cout << " Jugador actual: " << actualPlayer->name << "       Puntos: " << to_string(actualPlayer->points) <<  endl;
                    cout << " Fichas: " << actualPlayer->GetCoins() << endl;
                    Move(9 + (2*coinAt), table->maxDimension + 8);

                    cout << "^";

                }
                // Exit. Ctrl + X
                else if(key == 24){

                    int auxIntF = totalPositions->size;
                    for(int i = 0; i < auxIntF; i++){
                        NodePos *position = totalPositions->DeleteNode();
                        table->DeleteNode(position->x, position->y);
                    }

                    player1->AddScore();
                    player2->AddScore();

                    system("cls");
                    playing = false;
                    if(player1->points > player2->points){
                        cout << "\n\n\n\t\t\t\tFELICIDADES " << player1->name << " HAS GANADO CON " << player1->points << " PUNTOS!!!" << endl;
                    }
                    else if(player1->points < player2->points){
                        cout << "\n\n\n\t\t\t\tFELICIDADES " << player2->name << " HAS GANADO CON " << player2->points << " PUNTOS!!!" << endl;
                    }else{
                        cout << "\n\n\n\t\t\t\tEMPATEEEEE CON " << player2->points << " PUNTOS!!!" << endl;
                    }
                    Sleep(5000);
                    cout << "Saliendo del juego..." << endl;
                    Sleep(2000);
                    system("cls");
                    GeneralMenu();
                }
                // Available coins. Ctrl + W
                else if(key == 23){
                    coins->GenerateReport();
                }
                // Coins of the player
                else if(key == 26){
                    actualPlayer->GenerateCoinsReport();
                }
                // Change coins. Ctrl + Y
                else if(key == 25 && xFinal == -1){
                    BagOfCoins *auxiliarBag = new BagOfCoins();
                    Move(0, 0);
                    cout << "Seleccione las fichas que desea eliminar" << endl;

                    bool deleteCoins = false;
                    coinAt = 0;
                    Move(0, table->maxDimension + 7);
                    cout << " Fichas: " << actualPlayer->GetCoins() << endl;
                    Move(9 + (2*coinAt), table->maxDimension + 8);

                    cout << "^";
                    while(!deleteCoins){

                        do{
                            key = getch();
                            if(key == -32){
                                key = getch();
                            }
                        }
                        // While the pressing key is different from Enter, Left, Right
                        while(key != 13 && key != 75 && key != 77);
                        switch(key){
                            case 75:
                                if(coinAt != 0){
                                    coinAt--;
                                    Move(0, table->maxDimension + 8);
                                    cout << "                                         ";
                                    Move(9 + (2*coinAt), table->maxDimension + 8);
                                    cout << "^";
                                }
                                break;
                            case 77:
                                if(coinAt != actualPlayer->coins->size - 1){
                                    coinAt++;
                                    Move(0, table->maxDimension + 8);
                                    cout << "                                         ";
                                    Move(9 + (2*coinAt), table->maxDimension + 8);
                                    cout << "^";
                                }
                                break;
                            case 13:
                                auxiliarBag->RepeatInsertNode(actualPlayer->coins->DeleteNodeAt(coinAt));
                                Move(0, 0);
                                cout << "                                                                     ";
                                Move(0,0);
                                cout << "Desea eliminar otra? 1)NO   ";
                                char de = getch();
                                if (de == 49){
                                    deleteCoins = true;
                                }else{


                                    coinAt = 0;
                                    Move(0, table->maxDimension + 7);
                                    cout << "                                                                                         " << endl;
                                    Move(0, table->maxDimension + 7);
                                    cout << " Fichas: " << actualPlayer->GetCoins() << endl;
                                    Move(9 + (2*coinAt), table->maxDimension + 8);
                                    cout << "                                                  ";
                                    Move(9 + (2*coinAt), table->maxDimension + 8);
                                    cout << "^";

                                }
                                break;
                        }
                    }

                    // Putting the coins back to the queue
                    int auxInt = auxiliarBag->size;
                    for(int i = 0; i < auxInt; ++i){
                        actualPlayer->AddCoins(coins->DeQueue());
                    }

                    for (int i = 0; i < auxInt; ++i) {
                        coins->EnQueue(auxiliarBag->DeleteNodeAt(0));
                    }
                    delete(auxiliarBag);

                    Move(0, 0);
                    cout << "                                                                                                            ";

                    // Pass the turn
                    PassTurn();
                    Move(0, table->maxDimension + 6);
                    cout << "                                                                                    " << endl;
                    cout << "                                                                                    " << endl;
                    Move(0, table->maxDimension + 6);
                    cout << " Jugador actual: " << actualPlayer->name << "       Puntos: " << to_string(actualPlayer->points) <<  endl;
                    cout << " Fichas: " << actualPlayer->GetCoins() << endl;
                }
                // Check word in the diccionary. Ctrl + T
                else if(key == 20 && xFinal != -1 && yFinal != -1){
                    if(table->CheckMatrixAt(xFinal, yFinal, dictionary, actualPlayer)){

                        for (int i = 0; i < auxBag->size; ++i) {
                            actualPlayer->AddCoins(coins->DeQueue());
                        }

                        auxBag->EmptyBag();

                        PassTurn();

                        Move(0, table->maxDimension + 6);
                        cout << "                                                                                         " << endl << "                                                                                         " << endl <<  "                                                                                         " ;
                        Move(0, table->maxDimension + 6);
                        cout << " Jugador actual: " << actualPlayer->name << "       Puntos: " << to_string(actualPlayer->points) <<  endl;
                        cout << " Fichas: " << actualPlayer->GetCoins() << endl;
                        Move(9 + (2*coinAt), table->maxDimension + 8);

                        cout << "^";

                    }else{

                        int auxInt = auxBag->size;
                        for(int i = 0; i < auxInt; i++){
                            actualPlayer->AddCoins(auxBag->DeleteNodeAt(0));
                        }

                        auxInt = auxPositions->size;
                        for(int i = 0; i < auxInt; i++){
                            NodePos *position = auxPositions->DeleteNode();
                            totalPositions->DeleteNode();
                            Move(6 + (3*position->x), position->y + 3);
                            cout << " ";
                            table->DeleteNode(position->x, position->y);
                        }

                        Move(0, table->maxDimension + 6);
                        cout << "                                                                                 " << endl;
                        Move(0, table->maxDimension + 6);
                        cout << "Palabra no encontrada en el diccionario";
                        Sleep(1000);

                        Move(0, table->maxDimension + 6);
                        cout << "                                                                                         " << endl << "                                                                                         " << endl <<  "                                                                                         " ;
                        Move(0, table->maxDimension + 6);
                        cout << " Jugador actual: " << actualPlayer->name << "       Puntos: " << to_string(actualPlayer->points) <<  endl;
                        cout << " Fichas: " << actualPlayer->GetCoins() << endl;
                        Move(9 + (2*coinAt), table->maxDimension + 8);

                        cout << "^";

                    }
                    xFinal = yFinal = -1;
                    LtoR = UtoD = false;
                    table->GenerateReport();
                }
            }
        }
    }
}

// Create user and put it in the binary tree
void Logic::CreateUser() {
    string nameOfUser;

    Move(2, 8);
    printf("Ingrese nombre de usuario: \n");
    cin >> nameOfUser;
    users->addUser(nameOfUser);
    printf("Usuario ingresado con exito");
    Sleep(1000);
    system("cls");
    GameMenu();
}

// Place where we select the players
void Logic::StartGame() {
    // Initialize the placer in NULL.
    player1 = player2 = NULL;

    /*------PLAYER 1------*/
    player1 = SelectUser();
    if(player1 == NULL){
        do{
            if(ExitStartGame()){
                GameMenu();
                return;
            }
            player1 = SelectUser();
        }while(player1 == NULL);
    }
    player1->StartGame();

    /*------PLAYER 2------*/
    player2 = SelectUser();
    if(player2 == NULL || player2 == player1){
        do{
            if(ExitStartGame()){
                GameMenu();
                return;
            }
            player2 = SelectUser();
        }while(player2 == NULL || player2 == player1);
    }
    player2->StartGame();

    // Fill the queue in a random way
    delete(coins);
    coins = new Queue();
    srand(time(NULL));
    bag->FillBag();
    int selectedChar;
    for(int i = 0; i< 95;i++){
        selectedChar = rand() % bag->size;

        coins->EnQueue(bag->DeleteNodeAt(selectedChar));
    }
    // Playing the game
    Play();
}

// Exit from the selection of users
bool Logic::ExitStartGame() {
    bool exit = false;
    system("cls");

    bool bExit = true;
    int sOpt = 1, sKey;
    do{
        Move(0,6);
        printf("\n\tNo selecciono ni un jugador o selecciono jugador repetido. Desea salir o volver a la seleccion de jugadores? \n");
        printf("    \t1. Si deseo salir \n    \t2. No, si deseo jugar");
        Move(0, 7 + sOpt); printf("--->");

        do{
            sKey = getch();
            if(sKey == -32){
                sKey = getch();
            }
        }while(sKey != 72 && sKey != 80 && sKey != 13);

        switch(sKey){
            case 72:
                sOpt--;
                if(sOpt < 1){
                    sOpt = 2;
                }
                break;
            case 80:
                sOpt++;
                if(sOpt > 2){
                    sOpt = 1;
                }
                break;
            case 13:
                bExit = false;
                break;
        }

    }while(bExit);

    switch(sOpt){
        case 1:
            exit = true;
            break;
        case 2:
            exit = false;
            break;
        default:
            break;
    }

    system("cls");

    return exit;
}

// Print the table in the console
void Logic::PrintTable() {
    system("cls");
    for (int i = 0; i < table->maxDimension; ++i) {
        Move( 5, i+3);
        for (int j = 0; j < table->maxDimension; ++j) {
            cout << "| |";
        }
        cout << endl;
    }
    cout << endl << endl << endl << endl << endl << endl << endl;
    cout << "\tCtrl + X para salir. Ctrl + Z para fichas del jugador actual. Ctrl + W para fichas disponibles" << endl;
    cout << "\t        Ctrl + T para comprobar palabra ingresada. Ctrl + Y para cambiar fichas (Pierde turno)";
}

// Pass the turn to other player
void Logic::PassTurn() {
    if(actualPlayer == player1){
        actualPlayer = player2;
    }
    else{
        actualPlayer = player1;
    }
}