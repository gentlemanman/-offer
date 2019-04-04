//
// Created by zhaohan on 2019/3/2.
//
#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<int>& sequence, int begin, int end){
    if(begin > end) return true;
    int i = 0;
    for(; i < end; ++i){
        if(sequence[i] > sequence[end]) break;
    }
    for(int j = i; j < end; ++j){
        if(sequence[j] < sequence[end]) return false;
    }
    return  dfs(sequence, begin, i - 1) && dfs(sequence, i, end - 1);
}

bool VerifySquenceOfBST(vector<int> sequence) {
    if(sequence.empty()) return false;
    return dfs(sequence, 0, sequence.size() - 1);
}

