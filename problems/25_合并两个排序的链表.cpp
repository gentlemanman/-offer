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
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(!pHead1) return pHead2;
    if(!pHead2) return pHead1;
    ListNode* pHead = new ListNode(-1);
    ListNode* ans = pHead;
    while(pHead1 && pHead2){
        if(pHead1->val < pHead2->val){
            pHead->next = pHead1;
            pHead1 = pHead1->next;
        }
        else{
            pHead->next = pHead2;
            pHead2 = pHead2->next;
        }
        pHead = pHead->next;
    }
    if(pHead1) pHead->next = pHead1;
    if(pHead2) pHead->next = pHead2;
    return ans->next;
}

