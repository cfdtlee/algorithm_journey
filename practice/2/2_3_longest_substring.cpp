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

string get_longest_common_sub(string, string);
int max(int[], int);

int main()
{
    string x, y;
    cin >> x >> y;
    string result;
    result = get_longest_common_sub(x, y);
    cout << result;
}

string get_longest_common_sub(string x, string y)
{
    int len_x = int(x.length());
    int len_y = int(y.length());
    int dp[len_x];
    int i, j, max_len = 0;
    int max_i = 0;
    for (i = 0; i != len_y; ++i) {
        if (i == 0) {               // 初始化第一行
            for (j = 0; j != len_x; ++j) {
                dp[j] = int(x[j] == y[i]);
            }
        }
        else {
            for (j = len_x-1; j >=0; --j) {
                if (j == 0) {
                    dp[j] = int(x[j] == y[i]);
                }
                else {
                    if (x[j-1] == y[i-1])
                        dp[j] = int(x[j] == y[i]) + dp[j-1];
                    else
                        dp[j] = int(x[j] == y[i]);
                }
            }
        }
        int temp = max(dp, len_x);
        
        if (temp > max_len) {
            max_len = temp;
            max_i = i;
        }
    }
    //cout << "max_len = " << max_len << " from : index =" << max_i << endl;
    return y.substr(max_i-max_len+1, max_len);
}

int max(int dp[], int len_x)
{
    int max = 0;
    int i;
    for (i = 0; i != len_x; ++i) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    return max;
}