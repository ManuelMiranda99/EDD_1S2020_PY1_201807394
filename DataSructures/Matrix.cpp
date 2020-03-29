//
// Created by Manuel on 8/03/2020.
//

#include "Matrix.h"

Matrix::Matrix(int _dimension) {
    header = new MatrixNode(-1, -1 ,0);
    maxDimension = _dimension;
}

void Matrix::InsertNode(int _XCoord, int _YCoord, int _Multiplier) {
    MatrixNode *newNode = new MatrixNode(_XCoord, _YCoord, _Multiplier);

    MatrixNode *column = SearchColumn(_XCoord);
    MatrixNode *row = SearchRow(_YCoord);

    // First Case
    if(column == NULL && row == NULL){
        // Create Column
        column = CreateColumn(_XCoord);

        // Create Row
        row = CreateRow(_YCoord);
    }
    // Second Case
    else if(column == NULL && row != NULL){
        // Create Column
        column = CreateColumn(_XCoord);
    }
    // Third Case
    else if(column != NULL && row == NULL){
        // Create Row
        row = CreateRow(_YCoord);
    }
    newNode = InsertOrderedColumn(newNode, row);

    newNode = InsertOrderedRow(newNode, column);
}

Coin * Matrix::DeleteNode(int _xCoord, int _yCoord) {
    MatrixNode *column = SearchColumn(_xCoord);
    MatrixNode *row = SearchRow(_yCoord);

    Coin *returnCoin;

    if(column != NULL && row != NULL){
        returnCoin = DeleteOrderedColumn(row, _xCoord);
        DeleteOrderedRow(column, _yCoord);

        return returnCoin;
    }
    return NULL;
}

Coin * Matrix::DeleteOrderedColumn(MatrixNode *_root, int _xPos) {
    MatrixNode *aux1 = _root;

    while(aux1 != NULL){
        // Delete
        if(aux1->XCoord == _xPos) {
            // If the cell is not a special (x2 or x3) cell, we remove the pointers
            if (aux1->multiplier <= 1) {
                /*
                    aux1.previous ->          <- aux1.next
                                    <- aux1 ->
                */
                aux1->previous->next = aux1->next;

                aux1->next->previous = aux1->previous;
            }
            return aux1->coin;
        }
        aux1 = aux1->next;
    }

    return NULL;
}

Coin * Matrix::DeleteOrderedRow(MatrixNode *_root, int _yPos) {
    MatrixNode *aux1 = _root;

    while(aux1 != NULL){
        // Delete
        if(aux1->YCoord == _yPos) {
            // If the cell is not a special (x2 or x3) cell, we remove the pointers
            if (aux1->multiplier <= 1) {
                /*
                    aux1.up
                                aux1
                    aux1.down
                */
                aux1->up->down = aux1->down;

                aux1->down->up = aux1->up;
            }
            return aux1->coin;
        }
        aux1 = aux1->down;
    }

    return NULL;
}

void Matrix::GenerateReport() {
    if(header->down != NULL && header->next != NULL){

        string graph = "digraph Matrix {\n\n"
                       "\tnode [shape=box];\n\n"
                       "\t// Nodo raiz\n"
                       "\tMt[label=\"" + to_string(header->XCoord) + ", " + to_string(header->YCoord) + "\", width = 1.5, style=filled, fillcolor = firebrick1, group = 1];\n\n";

        /* -------------------- Go through each header row -------------------- */

        // Auxiliar variable to number the nodes
        int x = 1;
        // Auxiliar node to go through each header row
        MatrixNode *aux = header->down;
        graph += "\t// Filas\n"
                 "\tU0 [label=\"" + to_string(aux->XCoord) + ", " + to_string(aux->YCoord) + "\", pos=\"5.3, 3.5!\", width = 1.5, style = filled, fillcolor = bisque1, group=1]; \n";
        aux = aux->down;
        while(aux != NULL){
            graph += "\tU" + to_string(x) + " [label=\"" + to_string(aux->XCoord) + ", " + to_string(aux->YCoord) + "\", width = 1.5, style = filled, fillcolor = bisque1, group=1]; \n";
            x++;
            aux = aux->down;
        }
        graph += "\n\t//Linkear filas\n\t";

        /* -------------------- Link each the header Rows -------------------- */
        x = 0;
        aux = header->down;
        while(aux->down != NULL){
            graph += "U" + to_string(x) + "->";
            x++;
            aux = aux->down;
        }
        graph += "U" + to_string(x) + " [dir=both];\n\t";

        /* -------------------- Go through each header Column -------------------- */
        graph += "\t// Columnas\n";
        // Setting the auxiliar variable to number nodes to 0
        x = 0;
        // Setting the auxiliar node to go through each header column
        aux = header->next;
        while(aux != NULL){
            graph += "\tA" + to_string(x) + " [label=\"" + to_string(aux->XCoord) + ", " + to_string(aux->YCoord) + "\", width = 1.5, style = filled, fillcolor = bisque1, group=" + to_string(aux->XCoord + 2) + "]; \n";
            x++;
            aux = aux->next;
        }
        graph += "\n\t// Linkear columnas\n\t";

        /* -------------------- Link each header Column -------------------- */
        x = 0;
        aux = header->next;
        while(aux->next != NULL){
            graph += "A" + to_string(x) + "->";
            x++;
            aux = aux->next;
        }
        graph += "A" + to_string(x) + "  [dir=both];\n\t";

        /* -------------------- Link the principal nodes to the header -------------------- */
        graph += "\t// Nodo raiz con primera fila y columna\n"
                 "\tMt -> U0 [dir=both];\n\tMt -> A0 [dir=both]; \n\n";

        /* -------------------- Rank at the same row the columns -------------------- */
        x = 0;
        aux = header->next;
        string columns;
        while(aux != NULL){
            columns += "A" + to_string(x) + "; ";
            x++;
            aux = aux->next;
        }

        graph += "\t// Colocar columnas de manera alineada\n"
                 "\t {rank = same; Mt; " + columns + "} \n\n";

        // Go through each row generating the graphviz Node
        int xPos = 0, yPos = 0;
        graph += "\t// Creation of nodes\n";
        aux = header->down;
        while(aux != NULL){
            graph += "\t// Fila " + to_string(yPos) + "\n";
            MatrixNode *temp_node = aux->next;
            xPos = 0;
            while(temp_node != NULL){

                // If the node have a coin on it
                if(temp_node->coin != NULL){
                    graph += "\tN" + to_string(temp_node->XCoord) + "_L" + to_string(temp_node->YCoord) + " [label=\"" + temp_node->coin->letter + "\", width=1.5, group = " + to_string(temp_node->XCoord + 2) + ", style = filled, fillcolor = salmon];\n";
                }
                // If the node doesnt have a coin, it is just a special cell
                else{
                    // If the multiplier is x2
                    string color;
                    if(temp_node->multiplier == 2){
                        color = "cadetblue";
                    }
                    // If the multiplier is x3
                    else{
                        color = "indianred";
                    }
                    graph += "\tN" + to_string(temp_node->XCoord) + "_L" + to_string(temp_node->YCoord) + " [label=\"x" + to_string(temp_node->multiplier) + "\", width=1.5, group = " + to_string(temp_node->XCoord + 2) + ", style = filled, fillcolor = " + color + "];\n";
                }
                temp_node = temp_node->next;
                xPos++;
            }
            graph += "\n\n";
            aux = aux->down;
            yPos++;
        }

        //  Linking the nodes by row and rank in the same row
        xPos = 0; yPos = 0;
        aux = header->down;
        while(aux != NULL){
            graph += "\t// Linkeando Fila " + to_string(yPos) + "\n"
                     "\tU" + to_string(yPos);
            string rankSame = "U" + to_string(yPos);
            MatrixNode *temp_node = aux->next;
            while(temp_node != NULL){

                graph += "->N" + to_string(temp_node->XCoord) +"_L" + to_string(temp_node->YCoord) + "";

                rankSame += "; N"+ to_string(temp_node->XCoord) +"_L" + to_string(temp_node->YCoord);

                temp_node = temp_node->next;
            }
            graph += " [dir=both];\n\n"
                     "{rank = same; " + rankSame + "}"
                     "\n\n";
            aux = aux->down;
            yPos++;
        }

        // Linking the nodes by column
        xPos = 0;
        aux = header->next;
        while(aux != NULL){
            graph += "\t// Linkeando Columna " + to_string(xPos) + "\n"
                     "\tA" + to_string(xPos);
            MatrixNode *temp_node = aux->down;
            while(temp_node != NULL){

                graph += "->N" + to_string(temp_node->XCoord) +"_L" + to_string(temp_node->YCoord) + "";

                temp_node = temp_node->down;
            }
            graph += ";\n\n";
            aux = aux->next;
            xPos++;
        }

        graph += "}";

        // Generate txt and image
        ofstream writeToFile;
        writeToFile.open("Tablero.txt", ios_base::out | ios_base::trunc);
        if(writeToFile.is_open()){
            writeToFile << graph;
            writeToFile.close();
        }

        system("dot -Tpng Tablero.txt -o C:/Users/Manuel/Desktop/Tablero.png");
        system("C:/Users/Manuel/Desktop/Tablero.png");
    }
}

MatrixNode *Matrix::CreateRow(int _y) {
    MatrixNode *headerRow = header;
    MatrixNode *row = InsertOrderedRow(new MatrixNode(-1, _y, 0), headerRow);
    return row;
}

MatrixNode *Matrix::CreateColumn(int _x) {
    MatrixNode *headerColumn = header;
    MatrixNode *column = InsertOrderedColumn(new MatrixNode(_x, -1, 0), headerColumn);
    return column;
}

MatrixNode * Matrix::InsertOrderedRow(MatrixNode *_newNode, MatrixNode *_header_Row) {
    MatrixNode *aux = _header_Row;
    bool flag = false;

    while(true){
        if(aux->YCoord == _newNode->YCoord){
            aux->XCoord = _newNode->XCoord;
            return aux;
        }
        else if(aux->YCoord > _newNode->YCoord){
            flag = true;
            break;
        }

        if(aux->down != NULL){
            aux = aux->down;
        }
        else{
            break;
        }
    }

    if(flag){
        /*
            aux.up
            _newNode
            aux
        */
        _newNode->down = aux;
        aux->up->down = _newNode;
        _newNode->up = aux->up;
        aux->up = _newNode;
    }
    else{
        aux->down = _newNode;
        _newNode->up = aux;
    }
    return _newNode;
}

MatrixNode * Matrix::InsertOrderedColumn(MatrixNode *_newNode, MatrixNode *_header_Column) {
    MatrixNode *aux = _header_Column;
    bool flag = false;

    while(true){
        if(aux->XCoord == _newNode->XCoord){
            aux->YCoord = _newNode->YCoord;
            return aux;
        }else if(aux->XCoord > _newNode->XCoord){
            flag = true;
            break;
        }

        if(aux->next != NULL){
            aux = aux->next;
        }else{
            break;
        }
    }

    if(flag){
        /*
            aux.previous -><- _newNode -><- aux
        */
        _newNode->next = aux;
        aux->previous->next = _newNode;
        _newNode->previous = aux->previous;
        aux->previous = _newNode;
    }else{
        aux->next = _newNode;
        _newNode->previous = aux;
    }
    return _newNode;
}

MatrixNode *Matrix::SearchRow(int _y) {
    MatrixNode *aux = header;
    while(aux != NULL) {
        if (aux->YCoord == _y)
            return aux;
        aux = aux->down;
    }
    return NULL;
}

MatrixNode *Matrix::SearchColumn(int _x) {
    MatrixNode *aux = header;
    while(aux != NULL) {
        if (aux->XCoord == _x)
            return aux;
        aux = aux->next;
    }
    return NULL;
}

bool Matrix::PutCoin(int _xCoord, int _yCoord, Coin *_coin) {
    MatrixNode *column = SearchColumn(_xCoord);
    MatrixNode *row = SearchRow(_yCoord);

    MatrixNode *newNode = new MatrixNode(_xCoord, _yCoord, 1, _coin);

    if(column == NULL || row == NULL){

        if(column == NULL && row == NULL){
            column = CreateColumn(_xCoord);
            row = CreateRow(_yCoord);
        }
        else if(column == NULL && row != NULL){
            column = CreateColumn(_xCoord);
        }
            // Third Case
        else if(column != NULL && row == NULL){
            // Create Row
            row = CreateRow(_yCoord);
        }
        newNode = InsertOrderedColumn(newNode, row);
        newNode = InsertOrderedRow(newNode, column);
        // Return true because the Node doesnt exist, that means that there is no coin there
        return true;
    }
    // The position exist
    else{
        // Return true if the position doesnt have a Coin. Return false if the position have a Coin
        newNode = InsertOrderedRow(newNode, column);
        newNode = InsertOrderedColumn(newNode, row);
        return PutCoinAt(row, _xCoord, _coin);
    }
}

bool Matrix::PutCoinAt(MatrixNode *_header, int _xPos, Coin *_coin) {
    while(_header->XCoord != _xPos){
        _header = _header->next;
    }
    if(_header->coin != NULL && _header->coin != _coin){
        return false;
    }
    else{
        _header->PutCoin(_coin);
        return true;
    }
}

bool Matrix::CheckMatrixAt(int _xPos, int _yPos, CircularDoubleList *_dictionary, User *_user) {

    MatrixNode *actualNode;
    MatrixNode *aux = SearchColumn(_xPos);
    bool flagV = false, flagH = false;

    // In this part of the code, we get the actual node where we put the coin
    while(aux->YCoord != _yPos){
        aux = aux->down;
    }

    actualNode = aux;

    // Check in a vertical way the word
    if(actualNode->up->coin != NULL || actualNode->down->coin != NULL){
        // If the up node is inmediatly up to the actual node, the coord is not a header and there is coin on it
        while(aux->up->YCoord == (aux->YCoord - 1) && aux->up->YCoord != -1 && aux->up->coin != NULL){
            aux = aux->up;
        }

        string upWord;

        // Generating the word that is from top to bottom
        while(aux != NULL && aux->down->YCoord == (aux->YCoord + 1) && aux->down->coin != NULL){
            upWord += aux->coin->letter;
            aux = aux->down;
        }

        // If the word isn't accepted, we return false, and the next validations never happen
        if(!_dictionary->CheckWord(upWord)){
            return false;
        }
        else{
            flagV = true;
        }
    }
    // We continue the analisis of the nodes for the next points
    if(actualNode->previous->coin != NULL || actualNode->next->coin != NULL){
        aux = actualNode;

        // If the previous node is inmediatly previous to the actual node, the coord is not a header and there is coin on it
        while(aux->previous->XCoord == (aux->XCoord - 1) && aux->previous->XCoord != -1 && aux->previous->coin != NULL){
            aux = aux->previous;
        }

        string horizontalWord;

        // Generating the word that is from left to right
        while(aux != NULL && aux->next->XCoord == (aux->XCoord + 1) && aux->next->coin != NULL){
            horizontalWord += aux->coin->letter;
            aux = aux->next;
        }

        // If the word isn't accepted, we return false, and the next validations never happen
        if(!_dictionary->CheckWord(horizontalWord)){
            return false;
        }
        else{
            flagH = true;
        }

    }

    // Add the points to the user
    if(flagV && flagH){
        // Vertical Points
        aux = actualNode;
        VerticalPoints(aux, _user);
        aux = actualNode;
        HorizontalPoints(aux, _user);
        return true;
    }
    else if(flagV && !flagH){
        aux = actualNode;
        VerticalPoints(aux, _user);
        return true;
    }
    else if(!flagV && flagH){
        aux = actualNode;
        HorizontalPoints(aux, _user);
        return true;
    }

    // If we get to this place, it means that the player only put one coin

    return false;
}

void Matrix::HorizontalPoints(MatrixNode *aux, User *_user) {
    // If the previous node is inmediatly previous to the actual node, the coord is not a header and there is coin on it
    while(aux->previous->XCoord == (aux->XCoord - 1) && aux->previous->XCoord != -1 && aux->previous->coin != NULL){
        aux = aux->previous;
    }

    // Generating the word that is from left to right
    while(aux != NULL && aux->next->XCoord == (aux->XCoord + 1) && aux->next->coin != NULL){
        _user->GetPoints(aux->GetPoints());
        aux = aux->next;
    }
}

void Matrix::VerticalPoints(MatrixNode *aux, User *_user) {
    // If the up node is inmediatly up to the actual node, the coord is not a header and there is coin on it
    while(aux->up->YCoord == (aux->YCoord - 1) && aux->up->YCoord != -1 && aux->up->coin != NULL){
        aux = aux->up;
    }

    // Adding the points to the player
    while(aux != NULL && aux->down->YCoord == (aux->YCoord + 1) && aux->down->coin != NULL){
        _user->GetPoints(aux->GetPoints());
        aux = aux->down;
    }
}