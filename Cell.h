#define WALL '0'
#define CORRIDOR '.'
#define FOOD '*'
#define PLAYER1 '1'
#define PLAYER2 '2'
#include <iostream>

using namespace std;

class Cell {
public:
    Cell();
    Cell(int id);
    int getId();
    bool isWall();
    void setWall();
    void setCorridor();
    bool isCorridor();
    string getValue();
    void setValue(char value);
    void setPlayer1();
    void setPlayer2();
    bool isPlayer1();
    bool isPlayer2();
    bool hasPlayer();
    bool hasFood();
    void setFood();
    void eatFood();
//    char getCValue();
private:
    int id;
    char value;
    bool food;
};

