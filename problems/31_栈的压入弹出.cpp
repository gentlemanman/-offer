//
// Created by zhaohan on 2019/2/24.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    if(pushV.empty()) return false;
    stack<int> s;
    int j = 0;
    for(int i = 0; i < pushV.size(); ++i){
        s.push(pushV[i]);
        while(j < popV.size() && s.top() == popV[j]){
            s.pop();
            ++j;
        }
    }
    return s.empty();
}

