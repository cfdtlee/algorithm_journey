//
//  main.cpp
//  algorithm_practice
//
//  Created by Eric on 5/1/14.
//  Copyright (c) 2014 Eric. All rights reserved.
//
//  ABCBDAB BDCABA

#include <iostream>
#include <string>
using namespace std;
int c[200][200];
int b[200][200];
string x, y;

void lcs_length(string, string);
void create_lcs(int, int);
void printc();
int main()
{
    cout << "give me two string:" << endl;
    cin >> x;
    cin >> y;
    //lcs_length(7, 7);
    //create_lcs(7, 7);
    lcs_length(x, y);
    create_lcs(int(x.length()),int(y.length()));
    //printc();
}

void lcs_length(string x, string y)
{
    int m = int(x.length());
    int n = int(y.length());
    int i, j;
    for (i = 1; i < m; ++i) {
        c[i][0] = 0;
    }
    for (i = 0; i < n; ++i) {
        c[0][i] = 0;
    }
    for (i = 1; i <= m; ++i) {
        for (j = 1; j <= n; ++j) {
            if (x[i-1] == y[j-1]) {
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 2; //2  左上
            }
            else if (c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 3;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 1;
            }
        }
    }
}

void create_lcs(int i, int j)
{
    if (i == 0 || j == 0) {
        return;
    }
    cout << i << j << endl;
    if(b[i][j] == 2)
    {
        create_lcs(i-1, j-1);
        cout << x[i-1];
    }
    else if (b[i][j] == 3)
    {
        create_lcs(i-1, j);
    }
    else
    {
        create_lcs(i, j-1);
    }
}

void printc()
{
    int i, j;
    for (i = 0; i != 20; ++i) {
        for (j = 0; j != 20; ++j) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}