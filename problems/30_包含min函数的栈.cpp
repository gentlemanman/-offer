//
// Created by zhaohan on 2019/2/24.
//
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    void push(int value) {
        s1.push(value);
        if(s2.empty()){
            s2.push(value);
        }
        else{
            int top = s2.top();
            if(top < value)
                s2.push(top);
            else
                s2.push(value);
        }
    }
    void pop() {
        if(!s1.empty() && !s2.empty()){
            s1.pop();
            s2.pop();
        }
    }
    int top() {
        return s1.top();
    }
    int min() {
        if(!s2.empty()) return s2.top();
    }

private:
    stack<int> s1, s2;
};

