//
// Created by zhaohan on 2019/2/22.
//
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}

};
ListNode* ReverseList(ListNode* pHead) {
    if(!pHead) return nullptr;
    ListNode* reverseHead = nullptr;
    ListNode* pNode = pHead;
    ListNode* pPre = nullptr;
    while(pNode){
        ListNode* pNext = pNode->next;
        if(!pNext) reverseHead = pNode;
        pNode->next = pPre;
        pPre = pNode;
        pNode = pNext;
    }
    return reverseHead;
}

