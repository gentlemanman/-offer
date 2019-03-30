//
// Created by zhaohan on 2019/3/2.
//
#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<int>& sequence, int begin, int end){
    if(sequence.empty() || begin > end) return false;

    int root = sequence[end];
    int i = begin;
    for(; i < end; ++i){
        if(sequence[i] > root) break;
    }
    for(int j = i; j < end; ++j){
        if(sequence[j] < root) return false;
    }
    bool left = true;
    if(i > begin)
        left = dfs(sequence, begin, i - 1);
    bool right = true;
    if(i < end - 1)
        right = dfs(sequence, i, end - 1);
    return left && right;
}

bool VerifySquenceOfBST(vector<int> sequence) {
    return dfs(sequence, 0, sequence.size() - 1);
}

