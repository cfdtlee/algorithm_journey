//
//  main.cpp
//  algorithm_practice
//
//  Created by Eric on 5/1/14.
//  Copyright (c) 2014 Eric. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;

int dp_max_sum(int[], int);
int main()
{
    int n;
    
    cout << "how many num do you have:";
    cin >> n;
    int a[n];
    for (int i = 0; i != n; ++i) {
        cin >> a[i];
    }
    cout << "the max sum is:" << dp_max_sum(a, n) << endl;
}


int dp_max_sum(int a[], int n)
{
    int b = 0;
    int sum = 0;
    int i;
    for (i = 0; i != n; ++i) {
        if (b > 0) {
            b = b + a[i];
        }
        else {
            b = a[i];
        }
        if (b > sum) {
            sum = b;
        }
    }
    return sum;
}
