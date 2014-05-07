//
//  main.cpp
//  algorithm_practice
//
//  Created by Eric on 5/1/14.
//  Copyright (c) 2014 Eric. All rights reserved.
//


#include <iostream>
using namespace std;


void sort(int a[], int b[], int count)
{
    int i,j;
    int temp1,t2;
    for(i=0;i<count-1;i++)
        for(j=0;j<count-i-1;j++)
            if(a[j]>a[j+1])
            {
                temp1=a[j];
                a[j]=a[j+1];
                a[j+1]=temp1;
                t2 = b[j];
                b[j] = b[j+1];
                b[j+1] = t2;
            }
}


int main()
{
    int n;
    cout << "how many tasks:";
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i != n; ++i) {
        b[i] = i+1;
        cin >> a[i];
    }
    sort(a, b, n);
    cout << "the order should be:";
    for (int i = 0; i != n; ++i) {
        cout << b[i] << "(" << a[i] <<")";
    }
}

