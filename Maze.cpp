#include "Maze.h"

Maze::Maze(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    vector<vector<Cell> > vRows(rows);
    int id = 0;
    for (int i = 0; i < rows; i++) {
        vector<Cell> vCols(columns);
        for (int j = 0; j < columns; j++) {
            Cell *cell = new Cell(id);
            vCols[j] = *cell;
            id++;
        }
        vRows[i] = vCols;
    }
    this->maze = vRows;
    buildMazeOuterWalls();
    buildLeftInnerWalls();
    buildRightInnerWalls();
    setPlayersAndFood();
}

void Maze::buildMazeOuterWalls() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1) {
                this->maze[i][j].setWall();
            }
        }
    }
}

void Maze::buildLeftInnerWalls() {
    int x = 0;
    int y = 0;
    int x_aux = 0;
    int y_aux = 0;
    srand(time(NULL));

    // Only odd shapes
    int shape_one = ((rows / 2)*2) + 1;
    int shape_two = ((columns / 4)*2 + 1);
    int shape[2] = {shape_one, shape_two};

    // Adjust complexity and density relative to this->maze size
    int complexity = (int) (0.75 * (5 * (shape[0] + shape[1])));
    int density = (int) (0.75 * (((shape[0] / 2)*(shape[1] / 2))));
    vector<vector<int>> neighbours;

    int first_dim = 0;
    int random_pos = 0;
    bool firstTime = true;
    // Make aisles
    for (int i = 0; i < density; i++) {
        x = this->randomNumber(0, (shape[1] / 2))*2;
        y = this->randomNumber(0, (shape[0] / 2))*2;
        if (firstTime) {
            this->maze[1][1].setCorridor(); // DO NOT COMMENT!!
            this->maze[rows - 2][1].setCorridor(); // DO NOT COMMENT!!
            firstTime = false;
        } else {
            this->maze[y][x].setWall(); // DO NOT COMMENT!!
        }
        for (int j = 0; j < complexity; j++) {
            first_dim = 0;
            neighbours.clear();

            if (x > 1) {
                first_dim++;
                neighbours.resize(first_dim);
                neighbours[first_dim - 1].resize(2);
                neighbours[first_dim - 1][0] = y;
                neighbours[first_dim - 1][1] = x - 2;
            }
            if (x < shape[1] - 2) {
                first_dim++;
                neighbours.resize(first_dim);
                neighbours[first_dim - 1].resize(2);
                neighbours[first_dim - 1][0] = y;
                neighbours[first_dim - 1][1] = x + 2;
            }
            if (y > 1) {
                first_dim++;
                neighbours.resize(first_dim);
                neighbours[first_dim - 1].resize(2);
                neighbours[first_dim - 1][0] = y - 2;
                neighbours[first_dim - 1][1] = x;
            }
            if (y < shape[0] - 2) {
                first_dim++;
                neighbours.resize(first_dim);
                neighbours[first_dim - 1].resize(2);
                neighbours[first_dim - 1][0] = y + 2;
                neighbours[first_dim - 1][1] = x;
            }

            if (neighbours.size()) {
                random_pos = this->randomNumber(0, neighbours.size() - 1);
                y_aux = neighbours[random_pos][0];
                x_aux = neighbours[random_pos][1];
                if (this->maze[y_aux][x_aux].isCorridor()) {
                    this->maze[y_aux][x_aux].setWall();
                    this->maze[y_aux + (y - y_aux) / 2][x_aux + (x - x_aux) / 2].setWall();
                    x = x_aux;
                    y = y_aux;
                }
            }
        }
    }
    //    if(columns>30)
    for (int i = 1; i < rows - 1; i++) {
        maze[i][columns / 2 - 1].setCorridor();
        //        maze[i][columns/2-1].setValue('X');
    }
}

void Maze::buildRightInnerWalls() {
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < columns / 2; j++) {
            //            if (this->maze[i][j].isWall()) {
            this->maze[i][columns - 1 - j] = this->maze[i][j];
            //            }
        }
    }
}

string Maze::toString() {
    string str_maze;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            str_maze += this->maze[i][j].getValue();
        }
        str_maze += '\n';
    }
    return str_maze;
}

void Maze::setPlayersAndFood() {
    if (!maze[1][1].isWall()) {
        maze[1][1].setPlayer1();
        maze[1][columns - 2].setPlayer2();
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (!maze[i][j].isWall() && !maze[i][j].hasPlayer()) {
                maze[i][j].setFood();
            }
        }
    }

}

bool Maze::isCorridor(int x, int y) {
    return this->maze[x][y].isCorridor();
}

bool Maze::isWall(int x, int y) {
    return this->maze[x][y].isWall();
}

bool Maze::hasFood(int x, int y) {
    return this->maze[x][y].hasFood();
}

bool Maze::isPlayer1(int x, int y) {
    return this->maze[x][y].isPlayer1();
}

bool Maze::isPlayer2(int x, int y) {
    return this->maze[x][y].isPlayer2();
}

int Maze::randomNumber(int limit_inf, int limit_sup) {
    return limit_inf + (rand() % (int) limit_sup);
}
