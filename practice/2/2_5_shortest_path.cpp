//
//  main.cpp
//  algorithm_practice
//
//  Created by Eric on 5/1/14.
//  Copyright (c) 2014 Eric. All rights reserved.
//


#include <iostream>
#define SIZE 20
#define PARTS 7
using namespace std;
int dp_shortest_path(int[][SIZE]);
int get_part(int t);
int part[PARTS] = {0, 1, 3, 7, 10, 13, 15};
int path[PARTS];

int main()
{
    int g[SIZE][SIZE];
    for (int i = 0; i != SIZE; ++i) {
        for (int j = 0; j != SIZE; ++j) {
            g[i][j] = 9999;
        }
    }
    g[0][1] = 5, g[0][2] = 3, g[1][3] = 1, g[1][4] = 3, g[1][5] = 6;
    g[2][4] = 8, g[2][5] = 7, g[2][6] = 6, g[3][7] = 6, g[3][8] = 8;
    g[4][7] = 3, g[4][8] = 5, g[5][8] = 3, g[5][9] = 3, g[6][8] = 8, g[6][9] = 4;
    g[7][10] = 2, g[7][11] = 2, g[8][11] = 1, g[8][12] = 2, g[9][11] = 3, g[9][12] = 3;
    g[10][13] = 3, g[10][14] = 5, g[11][13] = 5, g[11][14] = 2, g[12][13] = 6, g[12][14] = 6;
    g[13][15] = 4, g[14][15] = 3;
    cout << "the shortest d is:" << dp_shortest_path(g);
    for (int k = 0; k != PARTS; ++k) {
        cout << path[k] << " ";
    }
    
}

int dp_shortest_path(int g[][SIZE])
{
    int d[16];
    for (int i = 0; i != 16 ; ++i) {
        d[i] = 999;
    }
    d[0] = 0;
    for (int i = 1; i != 16; ++i) {
        int p = get_part(i);
        cout << i << "is in part " << p << endl;
        for (int j = part[p - 1]; j != part[p]; ++j) {
            if (d[i] > g[j][i] + d[j]) {
                d[i] = g[j][i] + d[j];
                path[i] = j;
            }
        }
    }
    return d[15];
}

int get_part(int t)
{
    int p = 0;
    for (int i = 1; i != PARTS; ++i) {
        if (t >= part[i-1] && t < part[i]) {
            p = i-1;
            break;
        }
    }
    if (t == 15) {
        p = 6;
    }
    return p;
}