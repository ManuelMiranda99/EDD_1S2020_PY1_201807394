#include <iostream>
#include <windows.h>
#include <conio.h>
#include "DataSructures/CircularDoubleList.h"
#include "DataSructures/BinarySearchTree.h"

class Logic{
private:
    // Data Structures
    CircularDoubleList *dictionary = new CircularDoubleList();
    BinarySearchTree *users = new BinarySearchTree();
public:
    void Move(int, int);
    void GeneralMenu();
    void ReadFile();
    void GameMenu();
    void ReportsMenu();
    void MenuUsersReport();
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

}

void Logic::GameMenu() {

    bool bMenu = true;
    int sOpt = 1, sKey;
    do{
        Move(0,2);
        printf("\n\t\t\t\t MENU DE JUEGO \n");
        printf("    \t1. Crear Jugadores \n    \t\t2. Iniciar Partida \n    \t\t3. Regresar \n");
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
        printf("    \t1. Reporte de Diccionario \n    \t\t2. Reporte de Usuarios \n    \t\t3. Reporte de puntajes por jugador \n    \t\t4. Scoreboard \n    \t\t5. Regresar");
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
            User *reportPlayer = SelectUser();
            if(reportPlayer != NULL)
                reportPlayer->GenerateScoresReport();
            break;
    }

}

void Logic::MenuUsersReport() {

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
        printf("    \t1. Lectura de archivo \n    \t\t2. Jugar \n    \t\t3. Reportes \n    \t\t4. Salir");
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

User * Logic::SelectUser() {}