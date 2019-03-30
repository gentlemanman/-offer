//
// Created by zhaohan on 2019/2/10.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

vector<int> printListFromTailToHead(ListNode* head){
    vector<int> ans;
    if(!head) return ans;
    stack<ListNode*> s;
    while(head){
        s.push(head);
        head = head->next;
    }
    while (!s.empty()){
        ans.push_back(s.top()->val);
        s.pop();
    }
    return ans;
}
