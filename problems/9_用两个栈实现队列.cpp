//
// Created by zhaohan on 2019/2/11.
//
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack2.push(node);
    }

    int pop() {
        int ans = 0;
        if(stack2.size() == 0){
            while(!stack1.empty()){
                int t = stack1.top();
                stack1.pop();
                stack2.push(t);
            }
        }
        if(stack2.empty()) cout<<"queue is empty"<<endl;
        ans = stack2.top();
        stack2.pop();
        return ans;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
