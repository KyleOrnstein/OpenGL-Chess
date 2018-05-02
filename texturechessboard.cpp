/////////////////////////////////////////////////////////////////////
// Name: Kyle Ornstein
// Email: kjornste@syr.edu
// Assignment: Final Project
// Compiler: Visual Studio 2017
// Date: 4/5/18
// References:https://stackoverflow.com/questions/14028343/find-if-a-string-contains-a-character-in-c-boost-allowed check if a string is in an array (stringinarray)
/* Interactions:*/
/////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <functional>
#include <fstream>


#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define PI 3.14159265

using namespace std;

static GLsizei width, height;
static GLUquadricObj *qobj;
static int animationPeriod = 50;
static double xrotate = 0;
static double yrotate = 0;
static double zrotate = 0;
static unsigned int texture[2]; // Array of texture indices.
static float angle = 0.0; // Angle to rotate textured square.
static int id = 1;
static int whiteTurn = 1;
static int changeTurn = 0;
static int home = 1;
static int options = 0;
static int regularBoard = 1;
static int choosen = 0;
static int colorPieces = 1;
static int counter = 0;
static int doneOnce = 0;
static string userIn;
string temp;

// capture booleans
static int capPawnW1 = 0, capPawnW2 = 0, capPawnW3 = 0, capPawnW4 = 0, capPawnW5 = 0, capPawnW6 = 0, capPawnW7 = 0, capPawnW8 = 0;
static int capPawnB1 = 0, capPawnB2 = 0, capPawnB3 = 0, capPawnB4 = 0, capPawnB5 = 0, capPawnB6 = 0, capPawnB7 = 0, capPawnB8 = 0;
static int capKingW = 0, capQueenW = 0, capBishopW1 = 0, capBishopW2 = 0, capKnightW1 = 0, capKnightW2 = 0, capRookW1 = 0, capRookW2 = 0;
static int capKingB = 0, capQueenB = 0, capBishopB1 = 0, capBishopB2 = 0, capKnightB1 = 0, capKnightB2 = 0, capRookB1 = 0, capRookB2 = 0;

// capture booleans
static int capPawnW1Move = 0, capPawnW2Move = 0, capPawnW3Move = 0, capPawnW4Move = 0, capPawnW5Move = 0, capPawnW6Move = 0, capPawnW7Move = 0, capPawnW8Move = 0;
static int capPawnB1Move = 0, capPawnB2Move = 0, capPawnB3Move = 0, capPawnB4Move = 0, capPawnB5Move = 0, capPawnB6Move = 0, capPawnB7Move = 0, capPawnB8Move = 0;

//free Movement booleans
static double movePawnW1Free = 1, movePawnW2Free = 1, movePawnW3Free = 1, movePawnW4Free = 1, movePawnW5Free = 1, movePawnW6Free = 1, movePawnW7Free = 1, movePawnW8Free = 1;
static double movePawnB1Free = 1, movePawnB2Free = 1, movePawnB3Free = 1, movePawnB4Free = 1, movePawnB5Free = 1, movePawnB6Free = 1, movePawnB7Free = 1, movePawnB8Free = 1;
static double moveKingWFree = 1, moveQueenWFree = 1, moveBishopW1Free = 1, moveBishopW2Free = 1, moveKnightW1Free = 1, moveKnightW2Free = 1, moveRookW1Free = 1, moveRookW2Free = 1;
static double moveKingBFree = 1, moveQueenBFree = 1, moveBishopB1Free = 1, moveBishopB2Free = 1, moveKnightB1Free = 1, moveKnightB2Free = 1, moveRookB1Free = 1, moveRookB2Free = 1;

//Movement booleans
static double PawnW1Move = 0, PawnW2Move = 0, PawnW3Move = 0, PawnW4Move = 0, PawnW5Move = 0, PawnW6Move = 0, PawnW7Move = 0, PawnW8Move = 0;
static double PawnB1Move = 0, PawnB2Move = 0, PawnB3Move = 0, PawnB4Move = 0, PawnB5Move = 0, PawnB6Move = 0, PawnB7Move = 0, PawnB8Move = 0;
static double KingWMove = 0, QueenWMove = 0, BishopW0Move = 0, BishopW2Move = 0, KnightW0Move = 0, KnightW2Move = 0, RookW0Move = 0, RookW2Move = 0;
static double KingBMove = 0, QueenBMove = 0, BishopB0Move = 0, BishopB2Move = 0, KnightB0Move = 0, KnightB2Move = 0, RookB0Move = 0, RookB2Move = 0;

//movement translation variables
//x
static double movePawnW1x = 0, movePawnW2x = 0, movePawnW3x = 0, movePawnW4x = 0, movePawnW5x = 0, movePawnW6x = 0, movePawnW7x = 0, movePawnW8x = 0;
static double movePawnB1x = 0, movePawnB2x = 0, movePawnB3x = 0, movePawnB4x = 0, movePawnB5x = 0, movePawnB6x = 0, movePawnB7x = 0, movePawnB8x = 0;
static double moveKingWx = 0, moveQueenWx = 0, moveBishopW1x = 0, moveBishopW2x = 0, moveKnightW1x = 0, moveKnightW2x = 0, moveRookW1x = 0, moveRookW2x = 0;
static double moveKingBx = 0, moveQueenBx = 0, moveBishopB1x = 0, moveBishopB2x = 0, moveKnightB1x = 0, moveKnightB2x = 0, moveRookB1x = 0, moveRookB2x = 0;

//y
static double movePawnW1y = 0, movePawnW2y = 0, movePawnW3y = 0, movePawnW4y = 0, movePawnW5y = 0, movePawnW6y = 0, movePawnW7y = 0, movePawnW8y = 0;
static double movePawnB1y = 0, movePawnB2y = 0, movePawnB3y = 0, movePawnB4y = 0, movePawnB5y = 0, movePawnB6y = 0, movePawnB7y = 0, movePawnB8y = 0;
static double moveKingWy = 0, moveQueenWy = 0, moveBishopW1y = 0, moveBishopW2y = 0, moveKnightW1y = 0, moveKnightW2y = 0, moveRookW1y = 0, moveRookW2y = 0;
static double moveKingBy = 0, moveQueenBy = 0, moveBishopB1y = 0, moveBishopB2y = 0, moveKnightB1y = 0, moveKnightB2y = 0, moveRookB1y = 0, moveRookB2y = 0;

//z
static double movePawnW1z = 0, movePawnW2z = 0, movePawnW3z = 0, movePawnW4z = 0, movePawnW5z = 0, movePawnW6z = 0, movePawnW7z = 0, movePawnW8z = 0;
static double movePawnB1z = 0, movePawnB2z = 0, movePawnB3z = 0, movePawnB4z = 0, movePawnB5z = 0, movePawnB6z = 0, movePawnB7z = 0, movePawnB8z = 0;
static double moveKingWz = 0, moveQueenWz = 0, moveBishopW1z = 0, moveBishopW2z = 0, moveKnightW1z = 0, moveKnightW2z = 0, moveRookW1z = 0, moveRookW2z = 0;
static double moveKingBz = 0, moveQueenBz = 0, moveBishopB1z = 0, moveBishopB2z = 0, moveKnightB1z = 0, moveKnightB2z = 0, moveRookB1z = 0, moveRookB2z = 0;

bool isSelecting = false;
int closestName;
static unsigned int buffer[1024]; // Hit buffer.
static int hits;

//rook top
double eqn0[4] = { -1, 0, 0, .85 };
double eqn1[4] = { 1, 0, 0, 0.85 };
double eqn2[4] = {0, 0, 1, 0.85};
double eqn3[4] = {0, 0, -1, 0.85};

//bishop top
double eqn4[4] = { -1, -1, 0, .1 };
double eqn5[4] = { 1, 1, 0, -.2};

string chessboard[8][8];

void findClosestHit(int hits, unsigned int buffer[])
{
    unsigned int *ptr, minZ;
    
    minZ = 0xffffffff; // 2^32 - 1
    ptr = buffer;
    closestName = 0;
    for (int i = 0; i < hits; i++)
    {
        ptr++;
        if (*ptr < minZ)
        {
            minZ = *ptr;
            ptr += 2;
            closestName = *ptr;
            ptr++;
        }
        else ptr += 3;
    }
} // end findClosestHit

void writeStrokeString(void *font, const char *string)
{
    const char *c;
    
    for (c = string; *c != '\0'; c++) glutStrokeCharacter(font, *c);
}

void setCaptures(string piece){
    if (piece == "pawnW1")
        capPawnW1 = 1;
    else if (piece == "pawnW2")
        capPawnW2 = 1;
    else if (piece == "pawnW3")
        capPawnW3 = 1;
    else if (piece == "pawnW4")
        capPawnW4 = 1;
    else if (piece == "pawnW5")
        capPawnW5 = 1;
    else if (piece == "pawnW6")
        capPawnW6 = 1;
    else if (piece == "pawnW7")
        capPawnW7 = 1;
    else if (piece == "pawnW8")
        capPawnW8 = 1;
    else if (piece == "pawnB1")
        capPawnB1 = 1;
    else if (piece == "pawnB2")
        capPawnB2 = 1;
    else if (piece == "pawnB3")
        capPawnB3 = 1;
    else if (piece == "pawnB4")
        capPawnB4 = 1;
    else if (piece == "pawnB5")
        capPawnB5 = 1;
    else if (piece == "pawnB6")
        capPawnB6 = 1;
    else if (piece == "pawnB7")
        capPawnB7 = 1;
    else if (piece == "pawnB8")
        capPawnB8 = 1;
    else if (piece == "rookB1")
        capRookB1 = 1;
    else if (piece == "rookB2")
             capRookB2 = 1;
    else if (piece == "knightB1")
        capKnightB1 = 1;
    else if (piece == "knightB2")
        capKnightB2 = 1;
    else if (piece == "bishopB1")
        capBishopB1 = 1;
    else if (piece == "bishopB2")
        capBishopB1 = 1;
    else if (piece == "queenB")
        capQueenB = 1;
    else if (piece == "kingB")
        capKingB = 1;
    else if (piece == "rookW1")
        capRookW1 = 1;
    else if (piece == "rookW2")
        capRookW2 = 1;
    else if (piece == "knightW1")
        capKnightW1 = 1;
    else if (piece == "knightW2")
        capKnightW2 = 1;
    else if (piece == "bishopW1")
        capBishopW1 = 1;
    else if (piece == "bishopW2")
        capBishopW1 = 1;
    else if (piece == "queenW")
        capQueenW = 1;
    else if (piece == "kingW")
        capKingW = 1;
}

void turnChange(void){
    if(whiteTurn){
        zrotate += 5.0;
        if (zrotate >= 180.0){
            whiteTurn = 0;
            changeTurn = 0;
        }
    }
    else{
        zrotate += 5.0;
        if (zrotate >= 360.0){
            zrotate -=360;
            whiteTurn = 1;
            changeTurn = 0;
        }
    }
    glutPostRedisplay();
}

int checkPawnMovefreeW(string piece){
    for (int row = 0; row < 8; row++){
        for (int column = 0; column < 8; column++){
            if(chessboard[row][column].find(piece) != std::string::npos){
                if (chessboard[row-1][column] == "empty"){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
    }
    return 0;
}

int checkPawnMovefreeB(string piece){
    for (int row = 0; row < 8; row++){
        for (int column = 0; column < 8; column++){
            if(chessboard[row][column].find(piece) != std::string::npos){
                if (chessboard[row+1][column] == "empty"){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
    }
    return 0;
}

int checkPawnCapW(string piece){
    for (int row = 0; row < 8; row++){
        for (int column = 0; column < 8; column++){
            if(chessboard[row][column] == piece){
                if (chessboard[row-1][column-1].find("B") != std::string::npos && (row - 1 >= 0 && column -1 >= 0)){
                    return 1;
                }
                else if(chessboard[row-1][column+1].find("B") != std::string::npos && (row - 1 >= 0 && column + 1 <= 7)){
                    return 2;
                }
                else{
                    return 0;
                }
            }
        }
    }
    return 0;
}

int checkPawnCapB(string piece){
    for (int row = 0; row < 8; row++){
        for (int column = 0; column < 8; column++){
            if(chessboard[row][column] == piece){
                if (chessboard[row+1][column-1].find("W") != std::string::npos && (row + 1 <= 7 && column -1 >= 0)){
                    return 1;
                }
                else if(chessboard[row+1][column+1].find("W") != std::string::npos && (row + 1 <= 7 && column + 1 <= 7)){
                    return 2;
                }
                else{
                    return 0;
                }
            }
        }
    }
    return 0;
}

void MoveCapPawnW1(void){
    if (counter < 5){
        movePawnW1y += .5;
        if (checkPawnCapW("pawnW1") == 1) movePawnW1x -= .5;
        else if (checkPawnCapW("pawnW1") == 2) movePawnW1x += .5;
        counter++;
    }
    else{
        capPawnW1Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnW1") != std::string::npos){
                    if (checkPawnCapW("pawnW1") == 1) {
                        setCaptures(chessboard[row-1][column-1]);
                        chessboard[row-1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    if (checkPawnCapW("pawnW1") == 2) {
                        setCaptures(chessboard[row-1][column+1]);
                        chessboard[row-1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void MoveCapPawnW2(void){
    if (counter < 5){
        movePawnW2y += .5;
        if (checkPawnCapW("pawnW2") == 1) movePawnW2x -= .5;
        else if (checkPawnCapW("pawnW2") == 2) movePawnW2x += .5;
        counter++;
    }
    else{
        capPawnW2Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnW2") != std::string::npos){
                    if (checkPawnCapW("pawnW2") == 1) {
                        setCaptures(chessboard[row-1][column-1]);
                        chessboard[row-1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    else if (checkPawnCapW("pawnW2") == 2) {
                        setCaptures(chessboard[row-1][column+1]);
                        chessboard[row-1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void MoveCapPawnW3(void){
    if (counter < 5){
        movePawnW3y += .5;
        if (checkPawnCapW("pawnW3") == 1) movePawnW3x -= .5;
        else if (checkPawnCapW("pawnW3") == 2) movePawnW3x += .5;
        counter++;
    }
    else{
        capPawnW3Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnW3") != std::string::npos){
                    cout << "checkPawnCapW(pawnW3)" << checkPawnCapW("pawnW3") << endl;
                    if (checkPawnCapW("pawnW3") == 1) {
                        setCaptures(chessboard[row-1][column-1]);
                        chessboard[row-1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    else if (checkPawnCapW("pawnW3") == 2) {
                        setCaptures(chessboard[row-1][column+1]);
                        chessboard[row-1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void MoveCapPawnW4(void){
    if (counter < 5){
        movePawnW4y += .5;
        if (checkPawnCapW("pawnW4") == 1) movePawnW4x -= .5;
        else if (checkPawnCapW("pawnW4") == 2) movePawnW4x += .5;
        counter++;
    }
    else{
        capPawnW4Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnW4") != std::string::npos){
                    if (checkPawnCapW("pawnW4") == 1) {
                        setCaptures(chessboard[row-1][column-1]);
                        chessboard[row-1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    else if (checkPawnCapW("pawnW4") == 2) {
                        setCaptures(chessboard[row-1][column+1]);
                        chessboard[row-1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void MoveCapPawnW5(void){
    if (counter < 5){
        movePawnW5y += .5;
        if (checkPawnCapW("pawnW5") == 1) movePawnW5x -= .5;
        else if (checkPawnCapW("pawnW5") == 2) movePawnW5x += .5;
        counter++;
    }
    else{
        capPawnW5Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnW5") != std::string::npos){
                    if (checkPawnCapW("pawnW5") == 1) {
                        setCaptures(chessboard[row-1][column-1]);
                        chessboard[row-1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    else if (checkPawnCapW("pawnW5") == 2) {
                        setCaptures(chessboard[row-1][column+1]);
                        chessboard[row-1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void MoveCapPawnW6(void){
    if (counter < 5){
        movePawnW6y += .5;
        if (checkPawnCapW("pawnW6") == 1) movePawnW6x -= .5;
        else if (checkPawnCapW("pawnW6") == 2) movePawnW6x += .5;
        counter++;
    }
    else{
        capPawnW6Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnW6") != std::string::npos){
                    if (checkPawnCapW("pawnW6") == 1) {
                        setCaptures(chessboard[row-1][column-1]);
                        chessboard[row-1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    else if (checkPawnCapW("pawnW6") == 2) {
                        setCaptures(chessboard[row-1][column+1]);
                        chessboard[row-1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void MoveCapPawnW7(void){
    if (counter < 5){
        movePawnW7y += .5;
        if (checkPawnCapW("pawnW7") == 1) movePawnW7x -= .5;
        else if (checkPawnCapW("pawnW7") == 2) movePawnW7x += .5;
        counter++;
    }
    else{
        capPawnW7Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnW7") != std::string::npos){
                    if (checkPawnCapW("pawnW7") == 1) {
                        setCaptures(chessboard[row-1][column-1]);
                        chessboard[row-1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    else if (checkPawnCapW("pawnW7") == 2) {
                        setCaptures(chessboard[row-1][column+1]);
                        chessboard[row-1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void MoveCapPawnW8(void){
    if (counter < 5){
        movePawnW8y += .5;
        if (checkPawnCapW("pawnW8") == 1) movePawnW8x -= .5;
        else if (checkPawnCapW("pawnW8") == 2) movePawnW8x += .5;
        counter++;
    }
    else{
        capPawnW8Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnW8") != std::string::npos){
                    if (checkPawnCapW("pawnW8") == 1) {
                        cout << "cap 1" << endl;
                        setCaptures(chessboard[row-1][column-1]);
                        chessboard[row-1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    else if (checkPawnCapW("pawnW8") == 2) {
                        cout << "cap 2" << endl;
                        setCaptures(chessboard[row-1][column+1]);
                        chessboard[row-1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void MoveCapPawnB1(void){
    if (counter < 5){
        movePawnB1y -= .5;
        if (checkPawnCapB("pawnB1") == 1) movePawnB1x -= .5;
        else if (checkPawnCapB("pawnB1") == 2) movePawnB1x += .5;
        counter++;
    }
    else{
        capPawnB1Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnB1") != std::string::npos){
                    if (checkPawnCapB("pawnB1") == 1) {
                        setCaptures(chessboard[row+1][column-1]);
                        chessboard[row+1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    if (checkPawnCapB("pawnB1") == 2) {
                        setCaptures(chessboard[row+1][column+1]);
                        chessboard[row+1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void MoveCapPawnB2(void){
    if (counter < 5){
        movePawnB2y -= .5;
        if (checkPawnCapB("pawnB2") == 1) movePawnB2x -= .5;
        else if (checkPawnCapB("pawnB2") == 2) movePawnB2x += .5;
        counter++;
    }
    else{
        capPawnB2Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnB2") != std::string::npos){
                    if (checkPawnCapB("pawnB2") == 1) {
                        setCaptures(chessboard[row+1][column-1]);
                        chessboard[row+1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    else if (checkPawnCapB("pawnB2") == 2) {
                        setCaptures(chessboard[row+1][column+1]);
                        chessboard[row+1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void MoveCapPawnB3(void){
    if (counter < 5){
        movePawnB3y -= .5;
        if (checkPawnCapB("pawnB3") == 1) movePawnB3x -= .5;
        else if (checkPawnCapB("pawnB3") == 2) movePawnB3x += .5;
        counter++;
    }
    else{
        capPawnB3Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnB3") != std::string::npos){
                    cout << "checkPawnCapB(pawnB3)" << checkPawnCapB("pawnB3") << endl;
                    if (checkPawnCapB("pawnB3") == 1) {
                        setCaptures(chessboard[row+1][column-1]);
                        chessboard[row+1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    else if (checkPawnCapB("pawnB3") == 2) {
                        setCaptures(chessboard[row+1][column+1]);
                        chessboard[row+1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void MoveCapPawnB4(void){
    if (counter < 5){
        movePawnB4y -= .5;
        if (checkPawnCapB("pawnB4") == 1) movePawnB4x -= .5;
        else if (checkPawnCapB("pawnB4") == 2) movePawnB4x += .5;
        counter++;
    }
    else{
        capPawnB4Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnB4") != std::string::npos){
                    if (checkPawnCapB("pawnB4") == 1) {
                        setCaptures(chessboard[row+1][column-1]);
                        chessboard[row+1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    else if (checkPawnCapB("pawnB4") == 2) {
                        setCaptures(chessboard[row+1][column+1]);
                        chessboard[row+1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void MoveCapPawnB5(void){
    if (counter < 5){
        movePawnB5y -= .5;
        if (checkPawnCapB("pawnB5") == 1) movePawnB5x -= .5;
        else if (checkPawnCapB("pawnB5") == 2) movePawnB5x += .5;
        counter++;
    }
    else{
        capPawnB5Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnB5") != std::string::npos){
                    if (checkPawnCapB("pawnB5") == 1) {
                        setCaptures(chessboard[row+1][column-1]);
                        chessboard[row+1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    else if (checkPawnCapB("pawnB5") == 2) {
                        setCaptures(chessboard[row+1][column+1]);
                        chessboard[row+1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void MoveCapPawnB6(void){
    if (counter < 5){
        movePawnB6y -= .5;
        if (checkPawnCapB("pawnB6") == 1) movePawnB6x -= .5;
        else if (checkPawnCapB("pawnB6") == 2) movePawnB6x += .5;
        counter++;
    }
    else{
        capPawnB6Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnB6") != std::string::npos){
                    if (checkPawnCapB("pawnB6") == 1) {
                        setCaptures(chessboard[row+1][column-1]);
                        chessboard[row+1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    else if (checkPawnCapB("pawnB6") == 2) {
                        setCaptures(chessboard[row+1][column+1]);
                        chessboard[row+1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void MoveCapPawnB7(void){
    if (counter < 5){
        movePawnB7y -= .5;
        if (checkPawnCapB("pawnB7") == 1) movePawnB7x -= .5;
        else if (checkPawnCapB("pawnB7") == 2) movePawnB7x += .5;
        counter++;
    }
    else{
        capPawnB7Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnB7") != std::string::npos){
                    if (checkPawnCapB("pawnB7") == 1) {
                        setCaptures(chessboard[row+1][column-1]);
                        chessboard[row+1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    else if (checkPawnCapB("pawnB7") == 2) {
                        setCaptures(chessboard[row+1][column+1]);
                        chessboard[row+1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void MoveCapPawnB8(void){
    if (counter < 5){
        movePawnB8y -= .5;
        if (checkPawnCapB("pawnB8") == 1) movePawnB8x -= .5;
        else if (checkPawnCapB("pawnB8") == 2) movePawnB8x += .5;
        counter++;
    }
    else{
        capPawnB8Move = 0;
        counter = 0;
        changeTurn = 1;
        for (int row = 0; row < 8; row++){
            for (int column = 0; column < 8; column++){
                if(chessboard[row][column].find("pawnB8") != std::string::npos){
                    if (checkPawnCapB("pawnB8") == 1) {
                        cout << "cap 1" << endl;
                        setCaptures(chessboard[row+1][column-1]);
                        chessboard[row+1][column-1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                    }
                    else if (checkPawnCapB("pawnB8") == 2) {
                        cout << "cap 2" << endl;
                        setCaptures(chessboard[row+1][column+1]);
                        chessboard[row+1][column+1] = chessboard[row][column];
                        chessboard[row][column] = "empty";
                        
                    }
                    doneOnce = 1;
                }
            }
        }
        doneOnce = 0;
    }
    glutPostRedisplay();
}

void movePawnW1(void){
    if (checkPawnMovefreeW("pawnW1")) {
        if (counter < 5){
            movePawnW1y += .5;
            counter++;
        }
        else{
            PawnW1Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnW1") != std::string::npos){
                        if (chessboard[row-1][column-1] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row-1][column];
                            chessboard[row-1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    else
        PawnW1Move = 0;
    glutPostRedisplay();
}

void movePawnW2(void){
    if (checkPawnMovefreeW("pawnW2")) {
        if (counter < 5){
            movePawnW2y += .5;
            counter++;
        }
        else{
            PawnW2Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnW2") != std::string::npos){
                        if (chessboard[row-1][column] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row-1][column];
                            chessboard[row-1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    glutPostRedisplay();
}

void movePawnW3(void){
    if (checkPawnMovefreeW("pawnW3")) {
        if (counter < 5){
            movePawnW3y += .5;
            counter++;
        }
        else{
            PawnW3Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnW3") != std::string::npos){
                        if (chessboard[row-1][column] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row-1][column];
                            chessboard[row-1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    glutPostRedisplay();
}

void movePawnW4(void){
    if (checkPawnMovefreeW("pawnW4")) {
        if (counter < 5){
            movePawnW4y += .5;
            counter++;
        }
        else{
            PawnW4Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnW4") != std::string::npos){
                        if (chessboard[row-1][column] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row-1][column];
                            chessboard[row-1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    glutPostRedisplay();
}

void movePawnW5(void){
    if (checkPawnMovefreeW("pawnW5")) {
        if (counter < 5){
            movePawnW5y += .5;
            counter++;
        }
        else{
            PawnW5Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnW5") != std::string::npos){
                        if (chessboard[row-1][column] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row-1][column];
                            chessboard[row-1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    glutPostRedisplay();
}

void movePawnW6(void){
    if (checkPawnMovefreeW("pawnW6")) {
        if (counter < 5){
            movePawnW6y += .5;
            counter++;
        }
        else{
            PawnW6Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnW6") != std::string::npos){
                        if (chessboard[row-1][column] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row-1][column];
                            chessboard[row-1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    glutPostRedisplay();
}

void movePawnW7(void){
    if (checkPawnMovefreeW("pawnW7")) {
        if (counter < 5){
            movePawnW7y += .5;
            counter++;
        }
        else{
            PawnW7Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnW7") != std::string::npos){
                        if (chessboard[row-1][column] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row-1][column];
                            chessboard[row-1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    glutPostRedisplay();
}

void movePawnW8(void){
    if (checkPawnMovefreeW("pawnW8")) {
        if (counter < 5){
            movePawnW8y += .5;
            counter++;
        }
        else{
            PawnW8Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnW8") != std::string::npos){
                        if (chessboard[row-1][column] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row-1][column];
                            chessboard[row-1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    glutPostRedisplay();
}

void movePawnB1(void){
    if (checkPawnMovefreeB("pawnB1")) {
        if (counter < 5){
            movePawnB1y -= .5;
            counter++;
        }
        else{
            PawnB1Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnB1") != std::string::npos){
                        if (chessboard[row+1][column] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row+1][column];
                            chessboard[row+1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    glutPostRedisplay();
}

void movePawnB2(void){
    if (checkPawnMovefreeB("pawnB2")) {
        if (counter < 5){
            movePawnB2y -= .5;
            counter++;
        }
        else{
            PawnB2Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnB2") != std::string::npos){
                        if (chessboard[row+1][column] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row+1][column];
                            chessboard[row+1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    glutPostRedisplay();
}

void movePawnB3(void){
    if (checkPawnMovefreeB("pawnB3")) {
        if (counter < 5){
            movePawnB3y -= .5;
            counter++;
        }
        else{
            PawnB3Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnB3") != std::string::npos){
                        if (chessboard[row+1][column] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row+1][column];
                            chessboard[row+1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    glutPostRedisplay();
}

void movePawnB4(void){
    if (checkPawnMovefreeB("pawnB4")) {
        if (counter < 5){
            movePawnB4y -= .5;
            counter++;
        }
        else{
            PawnB4Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnB4") != std::string::npos){
                        if (chessboard[row+1][column] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row+1][column];
                            chessboard[row+1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    glutPostRedisplay();
}

void movePawnB5(void){
    if (checkPawnMovefreeB("pawnB5")) {
        if (counter < 5){
            movePawnB5y -= .5;
            counter++;
        }
        else{
            PawnB5Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnB5") != std::string::npos){
                        if (chessboard[row+1][column] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row+1][column];
                            chessboard[row+1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    glutPostRedisplay();
}

void movePawnB6(void){
    if (checkPawnMovefreeB("pawnB6")) {
        if (counter < 5){
            movePawnB6y -= .5;
            counter++;
        }
        else{
            PawnB6Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnB6") != std::string::npos){
                        if (chessboard[row+1][column] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row+1][column];
                            chessboard[row+1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    glutPostRedisplay();
}

void movePawnB7(void){
    if (checkPawnMovefreeB("pawnB7")) {
        if (counter < 5){
            movePawnB7y -= .5;
            counter++;
        }
        else{
            PawnB7Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnB7") != std::string::npos){
                        if (chessboard[row+1][column] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row+1][column];
                            chessboard[row+1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    glutPostRedisplay();
}

void movePawnB8(void){
    if (checkPawnMovefreeB("pawnB8")) {
        if (counter < 5){
            movePawnB8y -= .5;
            counter++;
        }
        else{
            PawnB8Move = 0;
            counter = 0;
            changeTurn = 1;
            for (int row = 0; row < 8; row++){
                for (int column = 0; column < 8; column++){
                    if(chessboard[row][column].find("pawnB8") != std::string::npos){
                        if (chessboard[row+1][column] == "empty" && !doneOnce){
                            temp = chessboard[row][column];
                            chessboard[row][column] = chessboard[row+1][column];
                            chessboard[row+1][column] = temp;
                            doneOnce = 1;
                        }
                    }
                }
            }
            doneOnce = 0;
        }
    }
    glutPostRedisplay();
}

void animate(int someValue) {
    if (changeTurn) turnChange();
    if (PawnW1Move) movePawnW1();
    if (PawnW2Move) movePawnW2();
    if (PawnW3Move) movePawnW3();
    if (PawnW4Move) movePawnW4();
    if (PawnW5Move) movePawnW5();
    if (PawnW6Move) movePawnW6();
    if (PawnW7Move) movePawnW7();
    if (PawnW8Move) movePawnW8();
    if (PawnB1Move) movePawnB1();
    if (PawnB2Move) movePawnB2();
    if (PawnB3Move) movePawnB3();
    if (PawnB4Move) movePawnB4();
    if (PawnB5Move) movePawnB5();
    if (PawnB6Move) movePawnB6();
    if (PawnB7Move) movePawnB7();
    if (PawnB8Move) movePawnB8();
    if (capPawnW1Move) MoveCapPawnW1();
    if (capPawnW2Move) MoveCapPawnW2();
    if (capPawnW3Move) MoveCapPawnW3();
    if (capPawnW4Move) MoveCapPawnW4();
    if (capPawnW5Move) MoveCapPawnW5();
    if (capPawnW6Move) MoveCapPawnW6();
    if (capPawnW7Move) MoveCapPawnW7();
    if (capPawnW8Move) MoveCapPawnW8();
    if (capPawnB1Move) MoveCapPawnB1();
    if (capPawnB2Move) MoveCapPawnB2();
    if (capPawnB3Move) MoveCapPawnB3();
    if (capPawnB4Move) MoveCapPawnB4();
    if (capPawnB5Move) MoveCapPawnB5();
    if (capPawnB6Move) MoveCapPawnB6();
    if (capPawnB7Move) MoveCapPawnB7();
    if (capPawnB8Move) MoveCapPawnB8();
    glutTimerFunc(animationPeriod, animate, 1);
}

void drawKing(double x, double y, double z, int c) {
    if(c == 1 )
        glColor3f(0.961, 0.961, 0.961);
    else if(c == 2)
        glColor3f(0, 0, 0);
    else if (c == 3)
        glColor3f(1.000, 0.973, 0.863);
    else if (c == 4)
        glColor3f(0.804, 0.522, 0.247);
    
    //bottom up
    glPushMatrix();//1
    glTranslatef(x, y, z);
    glRotatef(90, 1, 0, 0);
    glPushMatrix();//2
    
    glPushMatrix();
    glTranslatef(0, -2.35, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, 1.1, 1.1, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2.25, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .9, 1.1, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2.2, 0);
    glScalef(1, .2, 1);
    gluSphere(qobj, 1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .75, 1, .2, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -1.9, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .7, .75, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -1.9, 0);
    glScalef(1, .1, 1);
    gluSphere(qobj, .7, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .4, .6, 2, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .5, .4, 1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .1, 0);
    glScalef(1, .2, 1);
    gluSphere(qobj, 1, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .3, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .7, .8, .2, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .4, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .6, .6, .3, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .45, 0);
    glScalef(1, .1, 1);
    gluSphere(qobj, .7, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 1.1, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .6, .4, .6, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 1.3, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .2, .6, .2, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 1.33, 0);
    glScalef(1, .2, 1);
    gluSphere(qobj, .2, 40, 40);
    glPopMatrix();
    
    //cross
    glPushMatrix();//vertical
    glTranslatef(0, 1.62, 0);
    glScalef(.3, 1, .3);
    glutSolidCube(.5);
    glPopMatrix();
    
    glPushMatrix();//horizontal
    glTranslatef(0, 1.62, 0);
    glScalef(1, .3, .3);
    glutSolidCube(.5);
    glPopMatrix();
    
    glPopMatrix();//2
    glPopMatrix();//1
}

void drawQueen(double x, double y, double z, char c) {
    if(c == 1)
        glColor3f(0.961, 0.961, 0.961);
    else if(c == 2)
        glColor3f(0, 0, 0);
    else if (c == 3)
        glColor3f(1.000, 0.973, 0.863);
    else if (c == 4)
        glColor3f(0.804, 0.522, 0.247);

    
    //bottom up
    glPushMatrix();//1
    glTranslatef(x, y, z);
    glRotatef(90, 1, 0, 0);
    glPushMatrix();//2
    
    glPushMatrix();
    glTranslatef(0, -2.35, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, 1.1, 1.1, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2.25, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .9, 1.1, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2.2, 0);
    glScalef(1, .2, 1);
    gluSphere(qobj, 1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .75, 1, .2, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -1.9, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .7, .75, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -1.9, 0);
    glScalef(1, .1, 1);
    gluSphere(qobj, .7, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .4, .6, 2, 40, 40);
    glPopMatrix();
    
    glPushMatrix();//top of stem
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .5, .4, 1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .1, 0);
    glScalef(1, .2, 1);
    gluSphere(qobj, 1, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .3, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .7, .8, .2, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .4, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .6, .6, .3, 20, 20);
    glPopMatrix();
    
    glPushMatrix();// top of consistent base
    glTranslatef(0, .45, 0);
    glScalef(1, .1, 1);
    gluSphere(qobj, .7, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 1.1, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .6, .4, .6, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 1.1, 0);
    glScalef(1, .4, 1);
    gluSphere(qobj, .4, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 1.35, 0);
    gluSphere(qobj, .2, 40, 40);
    glPopMatrix();
    
    glPopMatrix();//2
    glPopMatrix();//1
}

void drawTopBishop(void){
    
    glPushMatrix();
    glClipPlane(GL_CLIP_PLANE5, eqn5);//left side
    glEnable(GL_CLIP_PLANE5);
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    gluCylinder(qobj, .7, 0, .8, 20, 20);
    glPopMatrix();
    glDisable(GL_CLIP_PLANE5);
    glPopMatrix();
    
    //with clipping planes
    glClipPlane(GL_CLIP_PLANE4, eqn4);//left side
    glEnable(GL_CLIP_PLANE4);
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    gluCylinder(qobj, .7, 0, .8, 20, 20);
    glPopMatrix();
    glDisable(GL_CLIP_PLANE4);
    
}

void drawBishop(double x, double y, double z, int c) {
    if(c == 1)
        glColor3f(0.961, 0.961, 0.961);
    else if(c == 2)
        glColor3f(0, 0, 0);
    else if (c == 3)
        glColor3f(1.000, 0.973, 0.863);
    else if (c == 4)
        glColor3f(0.804, 0.522, 0.247);
    
    //bottom up
    glPushMatrix();//1
    glTranslatef(x, y, z);
    glRotatef(90, 1, 0, 0);
    glPushMatrix();//2
    
    glPushMatrix();
    glTranslatef(0, -2.35, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, 1.1, 1.1, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2.25, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .9, 1.1, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2.2, 0);
    glScalef(1, .2, 1);
    gluSphere(qobj, 1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .75, 1, .2, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -1.9, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .7, .75, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -1.9, 0);
    glScalef(1, .1, 1);
    gluSphere(qobj, .7, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .4, .6, 2, 40, 40);
    glPopMatrix();
    
    glPushMatrix();//top of stem
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .5, .4, 1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .1, 0);
    glScalef(1, .2, 1);
    gluSphere(qobj, 1, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .3, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .7, .8, .2, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .4, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .6, .6, .3, 20, 20);
    glPopMatrix();
    
    glPushMatrix();// top of consistent base
    glTranslatef(0, .45, 0);
    glScalef(1, .1, 1);
    gluSphere(qobj, .7, 40, 40);
    glPopMatrix();
    
    //top of bishop
    glPushMatrix();
    glTranslatef(0, 1, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .7, .55, .5, 30, 30);
    glPopMatrix();
    
    //with clipping planes
    glPushMatrix();
    glTranslatef(0, 1, 0);
    drawTopBishop();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 1.8, 0);
    gluSphere(qobj, .2, 20, 20);
    glPopMatrix();
    
    glPopMatrix();//2
    glPopMatrix();//1
}

void fillKnight(void ){
    double t, y;
    double a = -1.5, b = 1.5, c = -.65, d = .65;
    
    glPushMatrix();
    glRotatef(-20, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//back curve to base
    for(double x = 0; x < 100; x = x + 1){
        a = -1.45, b = 1.5, c = -.65, d = .65;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 1.0);
        glVertex3f(1.5, -1.05, 1);
    }
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(-20, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//back curve to base
    for(double x = 0; x < 100; x = x + 1){
        a = -1.45, b = 1.5, c = -.65, d = .65;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 0.0);
        glVertex3f(1.5, -1.05, 0);
    }
    glEnd();
    glPopMatrix();
    
    glBegin(GL_TRIANGLE_STRIP);//nose
    glVertex3f(1.85, .3, 0);
    glVertex3f(1.5, -0.2, 0);
    
    glVertex3f(1.85, .3, 1);
    glVertex3f(1.5, -0.2, 1);
    
    glVertex3f(1.85, -0.2, 0);
    glVertex3f(1.85, -0.2, 0);
    
    glVertex3f(1.85, -0.2, 1);
    glVertex3f(1.85, -0.2, 1);
    glEnd();
    
    glPushMatrix();
    glTranslatef(1.08, .5, 0);
    glRotatef(45, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//top curve to nose
    for(double x = 0; x < 50; x = x + 1){
        a = -.7, b = .7, c = -.65, d = .65;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 1);
        glVertex3f(-.2, -.8, 1);
    }
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.08, .5, 0);
    glRotatef(45, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//top curve to nose
    for(double x = 0; x < 50; x = x + 1){
        a = -.7, b = .7, c = -.65, d = .65;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 0);
        glVertex3f(-.2, -.8, 0);
    }
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.35, -.85, 0);
    glBegin(GL_TRIANGLE_STRIP);//bottom right curve to base
    for(double x = 0; x < 100; x = x + 1)
    {
        a = -.67, b = .67, c = -.4, d = .4;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 1);
        glVertex3f(-1.45, -0.65, 1);
    }
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.35, -.85, 0);
    glBegin(GL_TRIANGLE_STRIP);//bottom right curve to base
    for(double x = 0; x < 100; x = x + 1)
    {
        a = -.67, b = .67, c = -.4, d = .4;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 0);
        glVertex3f(-1.45, -0.65, 0);
    }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glRotatef(-20, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//back to nose
    for(double x = 0; x < 93; x = x + 1){
        a = -1.45, b = 1.5, c = -.65, d = .65;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 1.0);
        glVertex3f(1.5, .33, 1);
    }
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(-20, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//back to nose
    for(double x = 0; x < 93; x = x + 1){
        a = -1.45, b = 1.5, c = -.65, d = .65;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 0.0);
        glVertex3f(1.5, .33, 0);
    }
    glEnd();
    glPopMatrix();
}

void drawTopKnight(void){
    double t, y;
    double a = -1.45, b = 1.5, c = -.65, d = .65;
    
    glPushMatrix();
    glRotatef(-20, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//back curve
    for(double x = 0; x < 100; x = x + 1)
    {
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 0.0);
        glVertex3f(y*y, t, 1);
    }
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.08, .5, 0);
    glRotatef(45, 0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);//top curve
    for(double x = 0; x < 100; x = x + 1)
    {
        a = -.7, b = .7, c = -.65, d = .65;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 0.0);
        glVertex3f(y*y, t, 1);
    }
    glEnd();
    glPopMatrix();
    
    glBegin(GL_TRIANGLE_STRIP);//nose
    glVertex3f(1.85, .3, 0);
    glVertex3f(1.85, .3, 1);
    
    glVertex3f(1.85, -0.2, 0);
    glVertex3f(1.85, -0.2, 1);
    
    glVertex3f(1.85, -0.2, 0);
    glVertex3f(1.85, -0.2, 1);
    
    glVertex3f(1.5, -0.2, 0);
    glVertex3f(1.5, -0.2, 1);
    glEnd();
    
    glPushMatrix();
    glTranslatef(1.35, -.85, 0);
    glBegin(GL_TRIANGLE_STRIP);//bottom right curve
    for(double x = 0; x < 100; x = x + 1)
    {
        a = -.67, b = .67, c = -.4, d = .4;
        t = a+ (b-a)* x / 100;
        y = c+ (d-c)* x / 100;
        glVertex3f(y*y, t, 0.0);
        glVertex3f(y*y, t, 1);
    }
    glEnd();
    glPopMatrix();
    
    glBegin(GL_TRIANGLE_STRIP);//base
    glVertex3f(1.5, -1.5, 0);
    glVertex3f(1.5, -1.5, 1);
    
    glVertex3f(-.1, -1.5, 0);
    glVertex3f(-.1, -1.5, 1);
    glEnd();
    
}

void drawKnight(double x, double y, double z, int c) {
    switch (c) {
        case 1:
            glColor3f(0.961, 0.961, 0.961);
            break;
        case 2:
            glColor3f(0, 0, 0);
            break;
        case 3:
            glColor3f(1.000, 0.973, 0.863);
            break;
        case 4:
            glColor3f(0.804, 0.522, 0.247);
            break;
        default:
            break;
    }

    glPushMatrix();
    glTranslatef(x, y, z);
    if(c == 1)
        glRotatef(90, 0, 0, 1);
    else if(c == 2)
        glRotatef(-90, 0, 0, 1);
    else if (c == 3)
        glRotatef(90, 0, 0, 1);
    else if (c == 4)
        glRotatef(-90, 0, 0, 1);
    glRotatef(90, 1, 0, 0);
    glPushMatrix();
    
    //bottom up
    glPushMatrix();
    glTranslatef(0, -2.35, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, 1.1, 1.1, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2.25, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .9, 1.1, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2.2, 0);
    glScalef(1, .2, 1);
    gluSphere(qobj, 1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .75, 1, .2, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-.6, -.65, -.35);
    glScalef(.85, .9, .7);
    fillKnight();
    drawTopKnight();
    glPopMatrix();
    
    glPopMatrix();
    glPopMatrix();
}

void drawRook(double x, double y, double z, int c) {
    if(c == 1)
        glColor3f(0.961, 0.961, 0.961);
    else if(c == 2)
        glColor3f(0, 0, 0);
    else if (c == 3)
        glColor3f(1.000, 0.973, 0.863);
    else if (c == 4)
        glColor3f(0.804, 0.522, 0.247);
    
    
    
    //bottom up
    glPushMatrix();//1
    glTranslatef(x, y, z);
    glRotatef(90, 1, 0, 0);
    glPushMatrix();//2
    
    glPushMatrix();
    glTranslatef(0, -2.35, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, 1.1, 1.1, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2.25, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .9, 1.1, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2.2, 0);
    glScalef(1, .2, 1);
    gluSphere(qobj, 1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -1.9, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .75, 1, .3, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -1.8, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .75, .75, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -1.7, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .7, .7, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -.2, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .6, .65, 1.5, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -0.15, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .65, .6, .05, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -0.05, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .8, .65, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glScalef(1, .2, 1);
    gluSphere(qobj, .9, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0.05, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .85, .9, .05, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0.1, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .9, .85, .05, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0.4, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .9, .9, .3, 20, 20);
    glPopMatrix();
    
    glClipPlane(GL_CLIP_PLANE0, eqn0);//right side
    glEnable(GL_CLIP_PLANE0);
    glClipPlane(GL_CLIP_PLANE1, eqn1);//right side
    glEnable(GL_CLIP_PLANE1);
    glClipPlane(GL_CLIP_PLANE2, eqn2);//right side
    glEnable(GL_CLIP_PLANE2);
    glClipPlane(GL_CLIP_PLANE3, eqn3);//right side
    glEnable(GL_CLIP_PLANE3);
    glPushMatrix();
    glTranslatef(0, 0.6, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .9, .9, .2, 20, 20);
    glDisable(GL_CLIP_PLANE0);
    glDisable(GL_CLIP_PLANE1);
    glDisable(GL_CLIP_PLANE2);
    glDisable(GL_CLIP_PLANE3);
    glPopMatrix();
    
    glPopMatrix();//2
    glPopMatrix();//1
}

void drawPawn(double x, double y, double z, char c) {
    if(c == 1)
        glColor3f(0.961, 0.961, 0.961);
    else if(c == 2)
        glColor3f(0, 0, 0);
    else if (c == 3)
        glColor3f(1.000, 0.973, 0.863);
    else if (c == 4)
        glColor3f(0.804, 0.522, 0.247);

    //bottom up
    glPushMatrix();//1
    glTranslatef(x, y, z);
    glRotatef(90, 1, 0, 0);
    glPushMatrix();//2
    
    glPushMatrix();
    glTranslatef(0, -2.35, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, 1.1, 1.1, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2.25, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .9, 1.1, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2.2, 0);
    glScalef(1, .2, 1);
    gluSphere(qobj, 1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -2, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .75, 1, .2, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -1.9, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .7, .75, .1, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -1.9, 0);
    glScalef(1, .1, 1);
    gluSphere(qobj, .7, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -.5, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .4, .6, 1.5, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .5, .4, .75, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .05, 0);
    glScalef(1, .1, 1);
    gluSphere(qobj, .75, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .35, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(qobj, .3, .75, .3, 30, 30);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .75, 0);
    gluSphere(qobj, .5, 20, 20);
    glPopMatrix();
    
    glPopMatrix();//2
    glPopMatrix();//1
}

struct BitMapFile{
    int sizeX;
    int sizeY;
    unsigned char *data;
};

// Routine to read a bitmap file.
// Works only for uncompressed bmp files of 24-bit color.
BitMapFile *getBMPData(string filename){
    BitMapFile *bmp = new BitMapFile;
    unsigned int size, offset, headerSize;
    
    // Read input file name.
    ifstream infile(filename.c_str(), ios::binary);
    
    // Get the starting point of the image data.
    infile.seekg(10);
    infile.read((char *) &offset, 4);
    
    // Get the header size of the bitmap.
    infile.read((char *) &headerSize,4);
    
    // Get width and column values in the bitmap header.
    infile.seekg(18);
    infile.read( (char *) &bmp->sizeX, 4);
    infile.read( (char *) &bmp->sizeY, 4);
    
    // Allocate buffer for the image.
    size = bmp->sizeX * bmp->sizeY * 24;
    bmp->data = new unsigned char[size];
    
    // Read bitmap data.
    infile.seekg(offset);
    infile.read((char *) bmp->data , size);
    
    // Reverse color from bgr to rgb.
    int temp;
    for (int i = 0; i < size; i += 3)
    {
        temp = bmp->data[i];
        bmp->data[i] = bmp->data[i+2];
        bmp->data[i+2] = temp;
    }
    
    return bmp;
}

// Load external textures.
void loadExternalTextures(){
    // Local storage for bmp image data.
    BitMapFile *image[3];
    
    // Load the texture.
    image[0] = getBMPData("Textures/chessboard.bmp");
    image[1] = getBMPData("Textures/woodBackground.bmp");
    image[2] = getBMPData("Textures/woodenBoard.bmp");
    
    // Activate texture index texture[0].
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    
    // Set texture parameters for wrapping.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    // Set texture parameters for filtering.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    // Specify an image as the texture to be bound with the currently active texture index.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[0]->sizeX, image[0]->sizeY, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image[0]->data);
    
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[1]->sizeX, image[1]->sizeY, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image[1]->data);
    
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[2]->sizeX, image[2]->sizeY, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image[2]->data);
    
}

void drawRadioButton(float radius, float x, float y, float z)
{
    float theta;
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x, y, z);
    for (int i = 0; i <= 30; i++) {
        theta = 2 * PI * i / 30;
        glVertex3f(x + cos(theta) * radius, y + sin(theta) * radius, z);
    }
    glEnd();
}

void drawBackground(void){
    glPushMatrix();
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f(-10.0, -10.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(10.0, -10.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(10.0, 10.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-10.0, 10.0, 0.0);
    glEnd();
    glPopMatrix();
}

void drawOptionsScreen(void){
    glDisable(GL_LIGHTING);
    drawBackground();
    glDisable(GL_TEXTURE_2D);
    glLineWidth(4);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(-4, 5, 0.3);
    glScalef(0.02, 0.02, 0.02);
    writeStrokeString(GLUT_STROKE_ROMAN, "Options");
    glPopMatrix();
    
    glLineWidth(2);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(-7, 2, 0.3);
    glScalef(0.008, 0.008, 0.008);
    writeStrokeString(GLUT_STROKE_ROMAN, "Color");
    glPopMatrix();
    
    glLineWidth(2);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(-4.4, 2, 0.3);
    glScalef(0.008, 0.008, 0.008);
    writeStrokeString(GLUT_STROKE_ROMAN, "of");
    glPopMatrix();
    
    glLineWidth(2);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(-3.25, 2, 0.3);
    glScalef(0.008, 0.008, 0.008);
    writeStrokeString(GLUT_STROKE_ROMAN, "pieces: ");
    glPopMatrix();
    
    glColor3f(0, 0, 0);
    glPushMatrix();
    if(isSelecting) glLoadName(3);
    drawRadioButton(1, -5, 0, .1);//regular piece colors
    if (colorPieces == 1) {
        glColor3f(1, 1, 0);
        drawRadioButton(.7, -5, 0, .11);//regular piece colors
    }
    glPopMatrix();
    
    glLineWidth(2);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(-6.5, -2, 0.3);
    glScalef(0.008, 0.008, 0.008);
    writeStrokeString(GLUT_STROKE_ROMAN, "regular");
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0, 0, 0);
    if(isSelecting) glLoadName(4);
    drawRadioButton(1, -1, 0, .1);//different piece colors
    if (colorPieces == 3) {
        glColor3f(1, 1, 0);
        drawRadioButton(.7, -1, 0, .11);//different piece colors
    }
    glPopMatrix();
    
    glLineWidth(2);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(-2.5, -2, 0.3);
    glScalef(0.008, 0.008, 0.008);
    writeStrokeString(GLUT_STROKE_ROMAN, "browns");
    glPopMatrix();
    
    glLineWidth(2);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(-7, -3.5, 0.3);
    glScalef(0.008, 0.008, 0.008);
    writeStrokeString(GLUT_STROKE_ROMAN, "board");
    glPopMatrix();
    
    glLineWidth(2);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(-4, -3.5, 0.3);
    glScalef(0.008, 0.008, 0.008);
    writeStrokeString(GLUT_STROKE_ROMAN, "colors: ");
    glPopMatrix();
    
    glColor3f(0, 0, 0);
    glPushMatrix();
    if(isSelecting) glLoadName(5);
    drawRadioButton(1, -5, -5.5, .1);//regular chessboard
    if (regularBoard) {
        glColor3f(1, 1, 0);
        drawRadioButton(.7, -5, -5.5, .11);//regular chessboard
    }
    glPopMatrix();
    
    glLineWidth(2);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(-6.5, -7.5, 0.3);
    glScalef(0.008, 0.008, 0.008);
    writeStrokeString(GLUT_STROKE_ROMAN, "regular");
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0, 0, 0);
    if(isSelecting) glLoadName(6);
    drawRadioButton(1, -1, -5.5, .1);//different chessboard
    if (!regularBoard) {
        glColor3f(1, 1, 0);
        drawRadioButton(.7, -1, -5.5, .11);//different chessboard
    }
    glPopMatrix();
    
    glLineWidth(2);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(-2.5, -7.5, 0.3);
    glScalef(0.008, 0.008, 0.008);
    writeStrokeString(GLUT_STROKE_ROMAN, "wooden");
    glPopMatrix();
    
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
}

void drawBubbles(double x, double y, double z){
    glColor3f(0, 0, 0);
    glPushMatrix();
    glScalef(x, y, z);
    glutSolidCube(8);
    glPopMatrix();
}

void drawHomeScreen(void){
    glDisable(GL_LIGHTING);
    drawBackground();
    glDisable(GL_TEXTURE_2D);
    glLineWidth(5);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(-4.7, 3, 0.3);
    glScalef(0.03, 0.03, 0.03);
    writeStrokeString(GLUT_STROKE_ROMAN, "Chess");
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-.4, 0.5, .2);
    if(isSelecting) glLoadName(1);
    drawBubbles(1, .2, .01);
    glPopMatrix();
    
    glLineWidth(2);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(-4, 0, 0.3);
    glScalef(0.01, 0.01, 0.01);
    writeStrokeString(GLUT_STROKE_ROMAN, "Start");
    glPopMatrix();
    
    glLineWidth(2);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(-.8, 0, 0.3);
    glScalef(0.01, 0.01, 0.01);
    writeStrokeString(GLUT_STROKE_ROMAN, "Game");
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.5, -1.6, .2);
    if(isSelecting) glLoadName(2);
    drawBubbles(.7, .2, .01);
    glPopMatrix();
    
    glLineWidth(2);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(-4, -2, 0.3);
    glScalef(0.01, 0.01, 0.01);
    writeStrokeString(GLUT_STROKE_ROMAN, "Options");
    glPopMatrix();
    
    glLineWidth(1);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(.1, -7.5, 0.3);
    glScalef(0.005, 0.005, 0.005);
    writeStrokeString(GLUT_STROKE_ROMAN, "A");
    glPopMatrix();
    
    glLineWidth(1);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(.7, -7.5, 0.3);
    glScalef(0.005, 0.005, 0.005);
    writeStrokeString(GLUT_STROKE_ROMAN, "Kyle");
    glPopMatrix();
    
    glLineWidth(1);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(2.1, -7.5, 0.3);
    glScalef(0.005, 0.005, 0.005);
    writeStrokeString(GLUT_STROKE_ROMAN, "Ornstein");
    glPopMatrix();
    
    glLineWidth(1);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(4.7, -7.5, 0.3);
    glScalef(0.005, 0.005, 0.005);
    writeStrokeString(GLUT_STROKE_ROMAN, "Product");
    
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
}

void drawBoard(void){
    double dist = -9;
    glPushMatrix();
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f(-10.0, -10.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(10.0, -10.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(10.0, 10.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-10.0, 10.0, 0.0);
    glEnd();
    glPopMatrix();
    
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    for(int x = 0; x < 8; x++){
        glLineWidth(3);
        glColor3f(1, 1, 0);
        glPushMatrix();
        glTranslatef(dist, -11.3, 0);
        glScalef(0.01, 0.01, 0.01);
        if (x == 0) writeStrokeString(GLUT_STROKE_ROMAN, "a");
        if (x == 1) writeStrokeString(GLUT_STROKE_ROMAN, "b");
        if (x == 2) writeStrokeString(GLUT_STROKE_ROMAN, "c");
        if (x == 3) writeStrokeString(GLUT_STROKE_ROMAN, "d");
        if (x == 4) writeStrokeString(GLUT_STROKE_ROMAN, "e");
        if (x == 5) writeStrokeString(GLUT_STROKE_ROMAN, "f");
        if (x == 6) writeStrokeString(GLUT_STROKE_ROMAN, "g");
        if (x == 7) writeStrokeString(GLUT_STROKE_ROMAN, "h");
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-11, dist, 0);
        glScalef(0.01, 0.01, 0.01);
        if (x == 0) writeStrokeString(GLUT_STROKE_ROMAN, "1");
        if (x == 1) writeStrokeString(GLUT_STROKE_ROMAN, "2");
        if (x == 2) writeStrokeString(GLUT_STROKE_ROMAN, "3");
        if (x == 3) writeStrokeString(GLUT_STROKE_ROMAN, "4");
        if (x == 4) writeStrokeString(GLUT_STROKE_ROMAN, "5");
        if (x == 5) writeStrokeString(GLUT_STROKE_ROMAN, "6");
        if (x == 6) writeStrokeString(GLUT_STROKE_ROMAN, "7");
        if (x == 7) writeStrokeString(GLUT_STROKE_ROMAN, "8");
        glPopMatrix();
        dist += 2.5;
    }
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
}

void drawSetUpBoard(void){
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHT0);
    if (!capKingB) {drawKing(1.25, 8.7, 2.5, colorPieces + 1);}
    if (!capQueenB) {drawQueen(-1.25, 8.7, 2.5, colorPieces + 1);}
    if (!capBishopB1) {drawBishop(3.75, 8.7, 2.5, colorPieces+ 1);}
    if (!capBishopB2) {drawBishop(-3.75, 8.7, 2.5, colorPieces+ 1);}
    if (!capKnightB1) {drawKnight(-6.25, 8.7, 2.5, colorPieces+ 1);}
    if (!capKnightB2) {drawKnight(6.25, 8.7, 2.5, colorPieces+ 1);}
    if (!capRookB1) {drawRook(-8.75, 8.7, 2.5, colorPieces+ 1);}
    if (!capRookB2) {drawRook(8.75, 8.7, 2.5, colorPieces+ 1);}
    if (!capPawnB1) {
        glPushMatrix();
        glTranslatef(movePawnB1x, movePawnB1y, movePawnB1z);
        if (isSelecting) glLoadName(15); drawPawn(-8.75, 6.2, 2.5, colorPieces + 1);
        glPopMatrix();
    }
    if (!capPawnB2) {
        glPushMatrix();
        glTranslatef(movePawnB2x, movePawnB2y, movePawnB2z);
        if (isSelecting) glLoadName(16);drawPawn(-6.25, 6.2, 2.5, colorPieces + 1);
        glPopMatrix();
    }
    if (!capPawnB3) {
        glPushMatrix();
        glTranslatef(movePawnB3x, movePawnB3y, movePawnB3z);
        if (isSelecting) glLoadName(17);drawPawn(-3.75, 6.2, 2.5, colorPieces + 1);
        glPopMatrix();
    }
    if (!capPawnB4) {
        glPushMatrix();
        glTranslatef(movePawnB4x, movePawnB4y, movePawnB4z);
        if (isSelecting) glLoadName(18);drawPawn(-1.25, 6.2, 2.5, colorPieces + 1);
        glPopMatrix();
    }
    if (!capPawnB5) {
        glPushMatrix();
        glTranslatef(movePawnB5x, movePawnB5y, movePawnB5z);
        if (isSelecting) glLoadName(19);drawPawn(1.25, 6.2, 2.5, colorPieces + 1);
        glPopMatrix();
    }
    if (!capPawnB6) {
        glPushMatrix();
        glTranslatef(movePawnB6x, movePawnB6y, movePawnB6z);
        if (isSelecting) glLoadName(20);drawPawn(3.75, 6.2, 2.5, colorPieces + 1);
        glPopMatrix();
    }
    if (!capPawnB7) {
        glPushMatrix();
        glTranslatef(movePawnB7x, movePawnB7y, movePawnB7z);
        if (isSelecting) glLoadName(21);drawPawn(6.25, 6.2, 2.5, colorPieces + 1);
        glPopMatrix();
    }
    if (!capPawnB8) {
        glPushMatrix();
        glTranslatef(movePawnB8x, movePawnB8y, movePawnB8z);
        if (isSelecting) glLoadName(22);drawPawn(8.75, 6.2, 2.5, colorPieces + 1);
        glPopMatrix();
    }
    if (!capKingW) {drawKing(1.25, -8.7, 2.5, colorPieces);}
    if (!capQueenW) {drawQueen(-1.25, -8.7, 2.5, colorPieces);}
    if (!capBishopW1) {drawBishop(-3.75, -8.7, 2.5, colorPieces);}
    if (!capBishopW2) {drawBishop(3.75, -8.7, 2.5, colorPieces);}
    if (!capKnightW1) {drawKnight(-6.25, -8.7, 2.5, colorPieces);}
    if (!capKnightW2) {drawKnight(6.25, -8.7, 2.5, colorPieces);}
    if (!capRookW1) {drawRook(-8.75, -8.7, 2.5, colorPieces);}
    if (!capRookW2) {drawRook(8.75, -8.7, 2.5, colorPieces);}
    if (!capPawnW1) {
        glPushMatrix();
        glTranslatef(movePawnW1x, movePawnW1y, movePawnW1z);
        if (isSelecting) glLoadName(7); drawPawn(-8.75, -6.2, 2.5, colorPieces);
        glPopMatrix();
    }
    if (!capPawnW2) {
        glPushMatrix();
        glTranslatef(movePawnW2x, movePawnW2y, movePawnW2z);
        if (isSelecting) glLoadName(8);drawPawn(-6.25, -6.2, 2.5, colorPieces);
        glPopMatrix();
    }
    if (!capPawnW3) {
        glPushMatrix();
        glTranslatef(movePawnW3x, movePawnW3y, movePawnW3z);
        if (isSelecting) glLoadName(9);drawPawn(-3.75, -6.2, 2.5, colorPieces);
        glPopMatrix();
    }
    if (!capPawnW4) {
        glPushMatrix();
        glTranslatef(movePawnW4x, movePawnW4y, movePawnW4z);
        if (isSelecting) glLoadName(10);drawPawn(-1.25, -6.2, 2.5, colorPieces);
        glPopMatrix();
    }
    if (!capPawnW5) {
        glPushMatrix();
        glTranslatef(movePawnW5x, movePawnW5y, movePawnW5z);
        if (isSelecting) glLoadName(11);drawPawn(1.25, -6.2, 2.5, colorPieces);
        glPopMatrix();
    }
    if (!capPawnW6) {
        glPushMatrix();
        glTranslatef(movePawnW6x, movePawnW6y, movePawnW6z);
        if (isSelecting) glLoadName(12);drawPawn(3.75, -6.2, 2.5, colorPieces);
        glPopMatrix();
    }
    if (!capPawnW7) {
        glPushMatrix();
        glTranslatef(movePawnW7x, movePawnW7y, movePawnW7z);
        if (isSelecting) glLoadName(13);drawPawn(6.25, -6.2, 2.5, colorPieces);
        glPopMatrix();
    }
    if (!capPawnW8) {
        glPushMatrix();
        glTranslatef(movePawnW8x, movePawnW8y, movePawnW8z);
        if (isSelecting) glLoadName(14);drawPawn(8.75, -6.2, 2.5, colorPieces);
        glPopMatrix();
    }
    glDisable(GL_LIGHT0);
    glEnable(GL_TEXTURE_2D);
    drawBoard();
}

void printArray(void){
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            std::cout << chessboard[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void fillArray(void){
    chessboard[7][0] = "rookW1";
    chessboard[7][1] = "knightW1";
    chessboard[7][2] = "bishopW1";
    chessboard[7][3] = "queenW";
    chessboard[7][4] = "kingW";
    chessboard[7][5] = "bishopW1";
    chessboard[7][6] = "knightW2";
    chessboard[7][7] = "rookW2";
    chessboard[6][0] = "pawnW1";
    chessboard[6][1] = "pawnW2";
    chessboard[6][2] = "pawnW3";
    chessboard[6][3] = "pawnW4";
    chessboard[6][4] = "pawnW5";
    chessboard[6][5] = "pawnW6";
    chessboard[6][6] = "pawnW7";
    chessboard[6][7] = "pawnW8";
    chessboard[0][0] = "rookB1";
    chessboard[0][1] = "knightB1";
    chessboard[0][2] = "bishopB1";
    chessboard[0][3] = "queenB";
    chessboard[0][4] = "kingB";
    chessboard[0][5] = "bishopB1";
    chessboard[0][6] = "knightB2";
    chessboard[0][7] = "rookB2";
    chessboard[1][0] = "pawnB1";
    chessboard[1][1] = "pawnB2";
    chessboard[1][2] = "pawnB3";
    chessboard[1][3] = "pawnB4";
    chessboard[1][4] = "pawnB5";
    chessboard[1][5] = "pawnB6";
    chessboard[1][6] = "pawnB7";
    chessboard[1][7] = "pawnB8";
    for (int i = 2; i < 6; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            chessboard[i][j] = "empty";
        }
    }
}

void drawAll(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    if (home){
        gluLookAt(0.0, 0.0, 15, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    }
    else{
        gluLookAt(0.0, 0.0, 25, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    }
    // Activate a texture.
    glBindTexture(GL_TEXTURE_2D, texture[id]);
    
    // Map the texture onto a square polygon.
    glPushMatrix();//1
    glRotatef(zrotate, 0.0, 0.0, 1.0);
    glRotatef(yrotate, 0.0, 1.0, 0.0);
    glRotatef(xrotate, 1.0, 0.0, 0.0);
    glPushMatrix();//2
    if (home){
        if (options)
            drawOptionsScreen();
        else drawHomeScreen();
    }
    else{
        drawSetUpBoard();
        printArray();
    }
    glPopMatrix();
    glPopMatrix();
}

void drawScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    isSelecting = 0;
    drawAll();
    glutSwapBuffers();
}

void setup(void){
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST); // Enable depth testing.
    qobj = gluNewQuadric();
    fillArray();
    
    // Create texture index array.
    glGenTextures(2, texture);
    
    // Load external texture and generate and load procedural texture.
    loadExternalTextures();
    
    // Turn on OpenGL texturing.
    glEnable(GL_TEXTURE_2D);
    
    // Specify how texture values combine with current surface color values.
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    
    //lighting stuff
    float matSpec[] = { 1, 1, 1, 1.0 };
    float matShine[] = { 200.0 };
    float matAmbAndDif[] = {1.0, 1, 1, 1.0};
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShine);
    
    float lightAmb[] = { .6, .6, .6, 1 };
    float lightDifAndSpec[] = { 1, 1, 1, 1 };
    float lightPos[] = { 0.0, 0, -7.0, 0 };
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(.8, .8, 0.8, 0);

}

void resize(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluPerspective(60.0, (float)w / (float)h, 1.0, 50.0);
    width = w;
    height = h;
    
    glMatrixMode(GL_MODELVIEW);
}

void keyInput(unsigned char key, int x, int y){
    switch (key){
            exit(0);
        case 13:
            if(!home) changeTurn = !changeTurn;
            glutPostRedisplay();
            break;
        case 27:
            if(options)
                options = 0;
            else if(!home){
                home = 1;
                id = 1;
                zrotate = 0;
            }
            else
                exit(0);
            glutPostRedisplay();
            break;
        case 'h':
            home = !home;
            if(home)
                id = 1;
            else
                id = 0;
            glutPostRedisplay();
            break;
        case 'r':
            whiteTurn = 1;
            counter = 0;
            
            // capture booleans
            capPawnW1 = 0, capPawnW2 = 0, capPawnW3 = 0, capPawnW4 = 0, capPawnW5 = 0, capPawnW6 = 0, capPawnW7 = 0, capPawnW8 = 0;
            capPawnB1 = 0, capPawnB2 = 0, capPawnB3 = 0, capPawnB4 = 0, capPawnB5 = 0, capPawnB6 = 0, capPawnB7 = 0, capPawnB8 = 0;
            capKingW = 0, capQueenW = 0, capBishopW1 = 0, capBishopW2 = 0, capKnightW1 = 0, capKnightW2 = 0, capRookW1 = 0, capRookW2 = 0;
            capKingB = 0, capQueenB = 0, capBishopB1 = 0, capBishopB2 = 0, capKnightB1 = 0, capKnightB2 = 0, capRookB1 = 0, capRookB2 = 0;
            
            //free Movement booleans
            movePawnW1Free = 1, movePawnW2Free = 1, movePawnW3Free = 1, movePawnW4Free = 1, movePawnW5Free = 1, movePawnW6Free = 1, movePawnW7Free = 1, movePawnW8Free = 1;
            movePawnB1Free = 1, movePawnB2Free = 1, movePawnB3Free = 1, movePawnB4Free = 1, movePawnB5Free = 1, movePawnB6Free = 1, movePawnB7Free = 1, movePawnB8Free = 1;
            moveKingWFree = 1, moveQueenWFree = 1, moveBishopW1Free = 1, moveBishopW2Free = 1, moveKnightW1Free = 1, moveKnightW2Free = 1, moveRookW1Free = 1, moveRookW2Free = 1;
            moveKingBFree = 1, moveQueenBFree = 1, moveBishopB1Free = 1, moveBishopB2Free = 1, moveKnightB1Free = 1, moveKnightB2Free = 1, moveRookB1Free = 1, moveRookB2Free = 1;
            
            //Movement booleans
            PawnW1Move = 0, PawnW2Move = 0, PawnW3Move = 0, PawnW4Move = 0, PawnW5Move = 0, PawnW6Move = 0, PawnW7Move = 0, PawnW8Move = 0;
            PawnB1Move = 0, PawnB2Move = 0, PawnB3Move = 0, PawnB4Move = 0, PawnB5Move = 0, PawnB6Move = 0, PawnB7Move = 0, PawnB8Move = 0;
            KingWMove = 0, QueenWMove = 0, BishopW0Move = 0, BishopW2Move = 0, KnightW0Move = 0, KnightW2Move = 0, RookW0Move = 0, RookW2Move = 0;
            KingBMove = 0, QueenBMove = 0, BishopB0Move = 0, BishopB2Move = 0, KnightB0Move = 0, KnightB2Move = 0, RookB0Move = 0, RookB2Move = 0;
            
            //movement translation variables
            //x
            movePawnW1x = 0, movePawnW2x = 0, movePawnW3x = 0, movePawnW4x = 0, movePawnW5x = 0, movePawnW6x = 0, movePawnW7x = 0, movePawnW8x = 0;
            movePawnB1x = 0, movePawnB2x = 0, movePawnB3x = 0, movePawnB4x = 0, movePawnB5x = 0, movePawnB6x = 0, movePawnB7x = 0, movePawnB8x = 0;
            moveKingWx = 0, moveQueenWx = 0, moveBishopW1x = 0, moveBishopW2x = 0, moveKnightW1x = 0, moveKnightW2x = 0, moveRookW1x = 0, moveRookW2x = 0;
            moveKingBx = 0, moveQueenBx = 0, moveBishopB1x = 0, moveBishopB2x = 0, moveKnightB1x = 0, moveKnightB2x = 0, moveRookB1x = 0, moveRookB2x = 0;
            
            //y
            movePawnW1y = 0, movePawnW2y = 0, movePawnW3y = 0, movePawnW4y = 0, movePawnW5y = 0, movePawnW6y = 0, movePawnW7y = 0, movePawnW8y = 0;
            movePawnB1y = 0, movePawnB2y = 0, movePawnB3y = 0, movePawnB4y = 0, movePawnB5y = 0, movePawnB6y = 0, movePawnB7y = 0, movePawnB8y = 0;
            moveKingWy = 0, moveQueenWy = 0, moveBishopW1y = 0, moveBishopW2y = 0, moveKnightW1y = 0, moveKnightW2y = 0, moveRookW1y = 0, moveRookW2y = 0;
            moveKingBy = 0, moveQueenBy = 0, moveBishopB1y = 0, moveBishopB2y = 0, moveKnightB1y = 0, moveKnightB2y = 0, moveRookB1y = 0, moveRookB2y = 0;
            
            //z
            movePawnW1z = 0, movePawnW2z = 0, movePawnW3z = 0, movePawnW4z = 0, movePawnW5z = 0, movePawnW6z = 0, movePawnW7z = 0, movePawnW8z = 0;
            movePawnB1z = 0, movePawnB2z = 0, movePawnB3z = 0, movePawnB4z = 0, movePawnB5z = 0, movePawnB6z = 0, movePawnB7z = 0, movePawnB8z = 0;
            moveKingWz = 0, moveQueenWz = 0, moveBishopW1z = 0, moveBishopW2z = 0, moveKnightW1z = 0, moveKnightW2z = 0, moveRookW1z = 0, moveRookW2z = 0;
            moveKingBz = 0, moveQueenBz = 0, moveBishopB1z = 0, moveBishopB2z = 0, moveKnightB1z = 0, moveKnightB2z = 0, moveRookB1z = 0, moveRookB2z = 0;
            fillArray();
            glutPostRedisplay();
            break;
        case 'x':
            xrotate += 5.0;
            if (xrotate > 360.0) xrotate -= 360.0;
            glutPostRedisplay();
            break;
        case 'X':
            xrotate -= 5.0;
            if (xrotate < 0.0) xrotate += 360.0;
            glutPostRedisplay();
            break;
        case 'y':
            yrotate += 5.0;
            if (yrotate > 360.0) yrotate -= 360.0;
            glutPostRedisplay();
            break;
        case 'Y':
            yrotate -= 5.0;
            if (yrotate < 0.0) yrotate += 360.0;
            glutPostRedisplay();
            break;
        case 'z':
            zrotate += 5.0;
            if (zrotate > 360.0) zrotate -= 360.0;
            glutPostRedisplay();
            break;
        case 'Z':
            zrotate -= 5.0;
            if (zrotate < 0.0) zrotate += 360.0;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

void specialKeyInput(int key, int x, int y) {
}

void mousePicking(int button, int state, int x, int y) {
    int viewport[4];
    
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        glGetIntegerv(GL_VIEWPORT, viewport);
        glSelectBuffer(1024, buffer);
        (void)glRenderMode(GL_SELECT);
        
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluPickMatrix((float)x, (float)(viewport[3] - y), 3.0, 3.0, viewport);
        
        gluPerspective(60.0, (float)width / (float)height, 1.0, 50.0);
        
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        glInitNames();
        glPushName(0);
        isSelecting = 1;
        drawAll();
        hits = glRenderMode(GL_RENDER);
        findClosestHit(hits, buffer);
        if (closestName == 1) {
            home = 0;
            id = choosen;
        }
        if (closestName == 2){
            options = 1;
        }
        if (closestName == 3){
            colorPieces = 1;
        }
        if (closestName == 4){
            colorPieces = 3;
        }
        if (closestName == 5) {
            regularBoard = 1;
            choosen = 0;
        }
        if (closestName == 6) {
            regularBoard = 0;
            choosen = 2;
        }
        if (whiteTurn){
            if (closestName == 7){
                if (checkPawnCapW("pawnW1") != 0){
                    capPawnW1Move = 1;
                }
                else if(checkPawnCapW("pawnW1") == 0)
                    PawnW1Move = 1;
            }
            if (closestName == 8){
                if (checkPawnCapW("pawnW2") != 0){
                    capPawnW2Move = 1;
                }
                else {
                    PawnW2Move = 1;
                }
            }
            if (closestName == 9){
                if (checkPawnCapW("pawnW3") != 0)
                    capPawnW3Move = 1;
                else
                    PawnW3Move = 1;
            }
            if (closestName == 10){
                if(checkPawnCapW("pawnW4") != 0)
                    capPawnW4Move = 1;
                else
                    PawnW4Move = 1;
            }
            if (closestName == 11){
                if(checkPawnCapW("pawnW5") != 0)
                    capPawnW5Move = 1;
                else
                    PawnW5Move = 1;
            }
            if (closestName == 12){
                if(checkPawnCapW("pawnW6") != 0)
                    capPawnW6Move = 1;
                else
                    PawnW6Move = 1;
            }
            if (closestName == 13){
                if(checkPawnCapW("pawnW7") != 0)
                    capPawnW7Move = 1;
                else
                    PawnW7Move = 1;
            }
            if (closestName == 14){
                if (checkPawnCapW("pawnW8") != 0)
                    capPawnW8Move = 1;
                else
                    PawnW8Move = 1;
            }
        }
        if (!whiteTurn){
            if (closestName == 15){
                if (checkPawnCapB("pawnB1") != 0){
                    capPawnB1Move = 1;
                }
                else if(checkPawnCapB("pawnB1") == 0)
                    PawnB1Move = 1;
            }
            if (closestName == 16){
                if (checkPawnCapB("pawnB2") != 0){
                    capPawnB2Move = 1;
                }
                else {
                    PawnB2Move = 1;
                }
            }
            if (closestName == 17){
                if (checkPawnCapB("pawnB3") != 0)
                    capPawnB3Move = 1;
                else
                    PawnB3Move = 1;
            }
            if (closestName == 18){
                if(checkPawnCapB("pawnB4") != 0)
                    capPawnB4Move = 1;
                else
                    PawnB4Move = 1;
            }
            if (closestName == 19){
                if(checkPawnCapB("pawnB5") != 0)
                    capPawnB5Move = 1;
                else
                    PawnB5Move = 1;
            }
            if (closestName == 20){
                if(checkPawnCapB("pawnB6") != 0)
                    capPawnB6Move = 1;
                else
                    PawnB6Move = 1;
            }
            if (closestName == 21){
                if(checkPawnCapB("pawnB7") != 0)
                    capPawnB7Move = 1;
                else
                    PawnB7Move = 1;
            }
            if (closestName == 22){
                if (checkPawnCapB("pawnB8") != 0)
                    capPawnB8Move = 1;
                else
                    PawnB8Move = 1;
            }
        }
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glutPostRedisplay();
    }
}

void mouseMotion(int x, int y) {
}

void printInteraction(void){
}

int main(int argc, char **argv){
    printInteraction();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(1000, 50);
    glutCreateWindow("Chess");
    setup();
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    glutSpecialFunc(specialKeyInput);
    glutMouseFunc(mousePicking);
    glutMotionFunc(mouseMotion);
    
    glutTimerFunc(5, animate, 1);
    glutMainLoop();
    return 0;
}
