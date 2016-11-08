#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include "Maze.h"
/***************************************************
 *  Window size
 ***************************************************/
#define WIDTH 1000
#define HEIGHT 1000
/***************************************************
 *  Key map
 ***************************************************/
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

using namespace std;
/***************************************************
 *  Functions declaration
 ***************************************************/
void display();
void movePlayer(int direction);
/***************************************************
 *  Global variables
 ***************************************************/
int columns;
int rows;
Maze *maze;

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Please check the parameters introduced";
        cout << "\n\tUsage: ./game ROWS COLUMNS";
        cout << "\n\tX and Y are the size on each cordinate axis";
        return 0;
    }
    rows = atoi(argv[2]);
    columns = atoi(argv[1]);
    cout << "[" << columns << "],[" << rows << "]" << endl;
    cout << "Initializing..." << endl;
    maze = new Maze(rows, columns);
    cout << "Maze created..." << endl;
    cout << maze->toString();

    //OPENGL INIT PARAMS
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Game");

    glutDisplayFunc(display);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, HEIGHT - 1, WIDTH - 1, 0);

    //glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

/***************************************************
 *  Funcion to display elements
 ***************************************************/
void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (maze->isWall(i, j)) {
                glColor3f(0, 0, 255);
                glBegin(GL_QUADS);
                glVertex2i((j + 1) * WIDTH / columns, i * HEIGHT / rows);
                glVertex2i((j + 1) * WIDTH / columns, (i + 1) * HEIGHT / rows);
                glVertex2i(j * WIDTH / columns, (i + 1) * HEIGHT / rows);
                glVertex2i(j * WIDTH / columns, i * HEIGHT / rows);
            }
            if (maze->isCorridor(i, j)) {
                glColor3f(0, 0, 0);
                glBegin(GL_QUADS);
                glVertex2i((j + 1) * WIDTH / columns, i * HEIGHT / rows);
                glVertex2i((j + 1) * WIDTH / columns, (i + 1) * HEIGHT / rows);
                glVertex2i(j * WIDTH / columns, (i + 1) * HEIGHT / rows);
                glVertex2i(j * WIDTH / columns, i * HEIGHT / rows);
            }
            if (maze->isPlayer1(i, j)) {
                glColor3f(0, 1, 1);
                glBegin(GL_QUADS);
                glVertex2i((j + 0.15) * WIDTH / columns, (i + 0.15) * HEIGHT / rows);
                glVertex2i((j + 0.85) * WIDTH / columns, (i + 0.15) * HEIGHT / rows);
                glVertex2i((j + 0.85) * WIDTH / columns, (i + 0.85) * HEIGHT / rows);
                glVertex2i((j + 0.15) * WIDTH / columns, (i + 0.85) * HEIGHT / rows);

            }
            if (maze->isPlayer2(i, j)) {
                glColor3f(0, 1, 0);
                glBegin(GL_QUADS);
                glVertex2i((j + 0.15) * WIDTH / columns, (i + 0.15) * HEIGHT / rows);
                glVertex2i((j + 0.85) * WIDTH / columns, (i + 0.15) * HEIGHT / rows);
                glVertex2i((j + 0.85) * WIDTH / columns, (i + 0.85) * HEIGHT / rows);
                glVertex2i((j + 0.15) * WIDTH / columns, (i + 0.85) * HEIGHT / rows);
            }
            if (maze->hasFood(i, j)) {
                glColor3f(1, 1, 0);
                glBegin(GL_POINT);
                glVertex2i((j + 0.35) * WIDTH / columns, (i + 0.35) * HEIGHT / rows);
                glVertex2i((j + 0.65) * WIDTH / columns, (i + 0.35) * HEIGHT / rows);
                glVertex2i((j + 0.65) * WIDTH / columns, (i + 0.65) * HEIGHT / rows);
                glVertex2i((j + 0.35) * WIDTH / columns, (i + 0.65) * HEIGHT / rows);
            }
        }
        glEnd();
    }
    glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            movePlayer(LEFT);
            break;
        case 's':
            movePlayer(DOWN);
            break;
        case 'd':
            movePlayer(RIGHT);
            break;
        case 'w':
            movePlayer(UP);
            break;
    }
}

void movePlayer(int direction){
    
}
