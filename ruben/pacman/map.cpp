#include <iostream>
// #include <random>
// #include <stdlib.h>
#include <time.h>
#include "map.h"
#include <vector>
using std::vector;

using namespace std;

void Map::mapEnvirons(int rows, int columns) {

    int row, column;
    char map[rows][columns];

    // Draw the environs
    for (row = 0; row < rows; row++) {
        for (column = 0; column < columns; column++) {
            if (row == 0 || row == rows-1) {
                map[row][column] = '0';
            }
            else if (row > 0 && row < rows-1 && (column == 0 || column == columns-1)) {
                map[row][column] = '0';
            }
            else {
                map[row][column] = '.';
            }
        }
    }

    /*// Draw the house
    int house_margin_left = (columns/2)-8;
    int house_margin_right = (columns/2)+8;
    int house_margin_top = (rows/2)-3;
    int house_margin_bottom = (rows/2)+2;

    for (row = 0; row < rows; row++) {
        for (column = 0; column < columns; column++) {
            // if (row == house_margin_top && (column >= house_margin_left && column <= house_margin_left+2) || (column >= house_margin_right-2 && column <= house_margin_right)) {
            if (row == house_margin_top && ((column >= house_margin_left && column <= house_margin_left+5) || (column >= house_margin_right-5 && column <= house_margin_right))) {
                map[row][column] = '0';
            }
            else if ((column == house_margin_left || column == house_margin_right) && row >= house_margin_top && row <= house_margin_bottom) {
                map[row][column] = '0';
            }
            else if (row == house_margin_bottom && column >= house_margin_left && column <= house_margin_right) {
                map[row][column] = '0';
            }
        }
    }*/

    // Some restrictions
    int row_restriction_top = 2;
    int row_restriction_bottom = rows-2;
    int row_restriction_left = 2;
    int row_restriction_right = columns/2;

    srand (time(NULL));

    // Get a random position
    // int random_row = this->randomNumber(row_restriction_top, row_restriction_bottom);
    // int random_column = this->randomNumber(row_restriction_left, row_restriction_right);

    // map[random_row][random_column] = '0';

    // Wikipedia's example

    // Some vars
    int x = 0;
    int y = 0;
    int x_aux = 0;
    int y_aux = 0;

    // Only odd shapes
    int shape_one = ((rows/2)*2)+1;
    int shape_two = ((columns/4)*2+1);
    int shape[2] = {shape_one, shape_two};

    // CHECKED!!
    // cout<<shape[0]<<" "<<shape[1]<<endl;
    // CHECKED!!
    
    // Adjust complexity and density relative to maze size
    int complexity = (int)(0.75*(5*(shape[0]+shape[1])));
    int density = (int)(0.75*(((shape[0]/2)*(shape[1]/2))));

    // CHECKED!!
    // cout<<complexity<<" "<<density<<endl;
    // CHECKED!!

    vector<vector<int>> neighbours;

    // PLAYING WITH VECTORS...

    // neighbours.resize(1);
    // neighbours[0].resize(2);

    // neighbours[0][0] = 12;
    // neighbours[0][1] = 24;

    // cout<<neighbours[0][0]<<" "<<neighbours[0][1]<<endl<<endl;

    // neighbours.resize(2);
    // neighbours[1].resize(2);

    // neighbours[1][0] = 48;
    // neighbours[1][1] = 96;

    // cout<<neighbours[0][0]<<" "<<neighbours[0][1]<<endl;
    // cout<<neighbours[1][0]<<" "<<neighbours[1][1]<<endl;

    // if (neighbours.empty()) { cout<<"IS EMPTY"<<endl; }
    // else { cout<<"IS NOT EMPTY"<<endl; }

    // neighbours.clear();

    // if (neighbours.empty()) { cout<<"IS EMPTY"<<endl; }
    // else { cout<<"IS NOT EMPTY"<<endl; }

    // neighbours.resize(1);
    // neighbours[0].resize(2);

    // neighbours[0][0] = 1;
    // neighbours[0][1] = 2;

    // cout<<neighbours[0][0]<<" "<<neighbours[0][1]<<endl<<endl;

    // neighbours.resize(2);
    // neighbours[1].resize(2);

    // neighbours[1][0] = 3;
    // neighbours[1][1] = 4;

    // cout<<neighbours[0][0]<<" "<<neighbours[0][1]<<endl;
    // cout<<neighbours[1][0]<<" "<<neighbours[1][1]<<endl;

    // PLAYING WITH VECTORS...

    int first_dim = 0;
    int random_pos = 0;

    // Make aisles
    for (int i = 0; i < density; i++) {
        x = this->randomNumber(0, (shape[1]/2))*2;
        y = this->randomNumber(0, (shape[0]/2))*2;

        // CHECKED!!
        map[y][x] = '0'; // DO NOT COMMENT!!
        // CHECKED!!
        // cout<<"X: "<<x<<" Y: "<<y<<endl;
        // CHECKED!!

        for (int j = 0; j < complexity; j++) {
            first_dim = 0;
            neighbours.clear();

            if (x > 1) {
                first_dim++;

                neighbours.resize(first_dim);
                neighbours[first_dim-1].resize(2);

                neighbours[first_dim-1][0] = y;
                neighbours[first_dim-1][1] = x-2;
            }
            if (x < shape[1]-2) {
                first_dim++;

                neighbours.resize(first_dim);
                neighbours[first_dim-1].resize(2);

                neighbours[first_dim-1][0] = y;
                neighbours[first_dim-1][1] = x+2;
            }
            if (y > 1) {
                first_dim++;

                neighbours.resize(first_dim);
                neighbours[first_dim-1].resize(2);

                neighbours[first_dim-1][0] = y-2;
                neighbours[first_dim-1][1] = x;
            }
            if (y < shape[0]-2) {
                first_dim++;

                neighbours.resize(first_dim);
                neighbours[first_dim-1].resize(2);

                neighbours[first_dim-1][0] = y+2;
                neighbours[first_dim-1][1] = x;
            }

            // CHECKED!!
            // cout<<"Neighbours: [";
            // for (int arr = 0; arr < neighbours.size(); arr++) {
            //     if (arr == 0) {
            //         cout<<"("<<neighbours[arr][0]<<", "<<neighbours[arr][1]<<")";
            //     } else {
            //         cout<<", ("<<neighbours[arr][0]<<", "<<neighbours[arr][1]<<")";
            //     }
            // }
            // cout<<"]"<<endl;
            // cout<<"Len neighbours: "<<neighbours.size()<<" "<<neighbours.size()<<endl<<endl;
            // CHECKED!!

            if (neighbours.size()) {
                random_pos = this->randomNumber(0, neighbours.size()-1);
                y_aux = neighbours[random_pos][0];
                x_aux = neighbours[random_pos][1];

                // CHECKED!!
                // cout<<"Y_:  "<<neighbours[random_pos][0]<<" -> "<<y_aux<<"  X_:  "<<neighbours[random_pos][0]<<""<<" -> "<<y_aux<<endl;
                // CHECKED!!

                if (map[y_aux][x_aux] == '.') {
                    map[y_aux][x_aux] = '0';
                    map[y_aux+(y-y_aux)/2][x_aux+(x-x_aux)/2] = '0';
                    x = x_aux;
                    y = y_aux;
                }
            }
        }
    }
    // Wikipedia's example




    // Mirrored map
    for (row = 0; row < rows; row++) {
        for (column = 0; column < columns/2; column++) {
            map[row][columns-column-1] = map[row][column];
        }
    }

    // Print the map
    for (row = 0; row < rows; row++) {
        for (column = 0; column < columns; column++) {
            cout<<map[row][column];
        }
        cout<<"\n";
    }

}

// int Map::randomSelection(int arr[]) {
//     return (sizeof(arr)/sizeof(arr[0]));
// }

int Map::randomNumber(int limit_inf, int limit_sup) {
    return limit_inf + (rand()%(int)limit_sup);
}