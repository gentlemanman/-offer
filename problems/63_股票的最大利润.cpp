//
// Created by Administrator on 2019/5/2.
// 股票
#include <iostream>
#include <vector>
using namespace std;
int MaxDiff(vector<int> num){
    if(num.size() < 2) return 0;
    int min_value = num[0];
    int max_diff = num[1] - num[0];

    for(int i = 2; i < num.size(); ++i){
        if(num[i - 1] < min_value) min_value = num[i - 1];
        int diff = num[i] - min_value;
        if(max_diff < diff)
            max_diff = diff;
    }
    return max_diff;
}

