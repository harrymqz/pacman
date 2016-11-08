#include <vector>
#include "Cell.h"
#include <iostream>
#include <stack>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Maze {
public:
    Maze(int rows, int columns);
    void buildMazeOuterWalls();
    void buildLeftInnerWalls();
    void buildRightInnerWalls();
    string toString();
    bool isWall(int x, int y);
    bool isCorridor(int x, int y);
    bool hasFood(int x, int y);
    bool isPlayer1(int x, int y);
    bool isPlayer2(int x, int y);
    int randomNumber(int limit_inf, int limit_sup);
    void setPlayersAndFood();
private:
    int rows;
    int columns;
    vector<vector<Cell> > maze;
};

