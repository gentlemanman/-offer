//
// Created by Administrator on 2019/5/4.
// 构建乘积数组
#include <iostream>
#include <vector>
using namespace std;

vector<int> multiply(const vector<int>& A) {
    int length = A.size();
    vector<int> B(length);
    if(A.size() <=0) return B;
    B[0] = 1;
    for(int i = 1; i < length; ++i){
        B[i] = B[i - 1] * A[i - 1];
    }
    int tmp = 1;
    for(int i = length - 2; i >= 0; --i){
        tmp *= A[i + 1];
        B[i] *= tmp;
    }
    return B;
}

