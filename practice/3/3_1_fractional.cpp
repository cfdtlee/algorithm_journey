//
//  main.cpp
//  algorithm_practice
//
//  Created by Eric on 5/1/14.
//  Copyright (c) 2014 Eric. All rights reserved.
//


#include <iostream>
#define N 5
using namespace std;





typedef struct
{
    int value;
    int weight;
    double xjb;
}ITEM;

int cmp(ITEM a, ITEM b)
{
    if (a.xjb > b.xjb) {
        return 1;
    }
    else return 0;
}

int main()
{
    ITEM item[N];
    item[0].value = 20, item[1].value = 30, item[2].value = 65, item[3].value = 40, item[4].value = 60;
    item[0].weight = 10, item[1].weight = 20, item[2].weight = 30, item[3].weight= 40, item[4].weight = 50;
    for (int i = 0;  i != N; ++i) {
        item[i].xjb = (double)item[i].value/(double)item[i].weight;
    }
    sort(item, item+N, cmp);
    int full = 100;
    cout << "We got:";
    for (int i = 0; i != N; ++i) {
        full -= item[i].weight;
        if (full > 0) {
            cout << "[" << item[i].value << ","<< item[i].weight<<"],";
        }
    }
    cout << "in bag"<<endl;
}


