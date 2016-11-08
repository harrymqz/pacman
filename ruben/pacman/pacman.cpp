#include <iostream>
#include <random>
#include <GL/glut.h>
#include "map.h"

using namespace std;
bool check_initial_conditions(int rows, int columns);

int main(void) {
    int rows = 31;
    int columns = 101;

    /*while (check_initial_conditions(rows, columns)) {
        cout<<"Type the number of rows do you want: ";
        cin>>rows;

        cout<<"Type the number of columns do you want: ";
        cin>>columns;
    }

    if (rows%2 != 0) {
        rows++;
    }

    if (columns%2 == 0) {
        columns++;
    }

    cout<<rows<<" "<<columns<<endl;*/


    class Map map;

    map.mapEnvirons(rows, columns);

    return 0;
}

bool check_initial_conditions(int rows, int columns) {
    if ((rows >= 33 && rows <= 300) && (columns >= 18 && columns <= 150)) {
        return false;
    } else {
        return true;
    }
}
