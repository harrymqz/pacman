#include "Cell.h"

Cell::Cell() {
    this->id = 0;
    this->value = CORRIDOR;
}

Cell::Cell(int id) {
    this->id = id;
    this->value = CORRIDOR;
}

void Cell::setValue(char value){
    this->value=value;
}

//char Cell::getCValue(){
//    return this->value;
//}

int Cell::getId() {
    return this->id;
}

bool Cell::isWall() {
    return value == WALL;
}

void Cell::setWall() {
    this->value = WALL;
}

void Cell::setCorridor() {
    this->value = CORRIDOR;
}

bool Cell::isCorridor() {
    return value == CORRIDOR;
}

string Cell::getValue() {
    string str(1,this->value);
    return str;
}

void Cell::eatFood() {
    this->food = false;
}

void Cell::setFood() {
    this->food = true;
}

bool Cell::hasFood() {
    return this->food;
}

bool Cell::isPlayer1() {
    return this->value==PLAYER1;
}

bool Cell::isPlayer2() {
    return this->value==PLAYER2;
}

bool Cell::hasPlayer() {
    return this->value==PLAYER1 || this->value==PLAYER2;
}

void Cell::setPlayer1() {
    this->value = PLAYER1;
}

void Cell::setPlayer2() {
    this->value = PLAYER2;
}






