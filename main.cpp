#include <iostream>
#include <windows.h>
#include <conio.h>
#include "DataSructures/CircularDoubleList.h"
#include "DataSructures/BinarySearchTree.h"
#include "DataSructures/Matrix.h"
#include "Library/json.hpp"
#include "DataSructures/Queue.h"

using json = nlohmann::json;

class Logic{
private:
    // Data Structures
    CircularDoubleList *dictionary = new CircularDoubleList();
    BinarySearchTree *users = new BinarySearchTree();
    Queue *coins = new Queue();
    Matrix *table;
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
    void CreateUser();

    // Random function for the coins
    void Random();

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
    printf("Ingrese ruta del archivo JSON: ");
    cin >> route;

    ifstream i(route);
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
            // Play
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
            //table->GenerateReport();
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
        //system("cls");
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
    }else{
        User *selectedUser = users->GetUser(sOpt);
        return selectedUser;
    }
}

void Logic::Play() {

}

void Logic::Random(){

}

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