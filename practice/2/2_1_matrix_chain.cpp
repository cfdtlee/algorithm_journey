//
//  main.cpp
//  algorithm_practice
//
//  Created by Eric on 5/1/14.
//  Copyright (c) 2014 Eric. All rights reserved.
//
//30 35 15 5 10 20 25

#include <iostream>
using namespace std;
void matrix_chain(int[], int);
void print_optimal(int, int);
void print_m_s();

int m[20][20], s[20][20];
int main(int argc, const char * argv[])
{
    
    int chain[20];
    int n;
    cin >> n;
    int i;
    for (i = 0; i != n; ++i) {
        cin >> chain[i];
    }
    matrix_chain(chain, n);
    print_m_s();
    //print_optimal(1, n);
    return 0;
}

void matrix_chain(int chain[], int n)
{
    int i, l, j, k, q;
    
    for (l = 2; l < n; ++l) {  //length of chain
        for (i = 1; i <= n-l+1; ++i) {  //
            j = i+l-1;
            m[i][j] = 999;
            for (k = i; k < j; ++k) {
                q = m[i][k] + m[k+1][j] + chain[i-1]*chain[k]*chain[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_m_s()
{
    int i, j;
    for (i = 0; i < 20; ++i) {
        for (j = 0; j < 20; ++j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (i = 0; i < 20; ++i) {
        for (j = 0; j < 20; ++j) {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}

void print_optimal(int i, int j)
{
    if (i == j) {
        cout << "A" << i;
    }
    else{
        cout << "(";
        print_optimal(i, s[i][j]);
        print_optimal(s[i][j]+1, j);
        cout << ")";
    }
}