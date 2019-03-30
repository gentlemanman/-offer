//
// Created by zhaohan on 2019/2/21.
//
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if(pListHead == nullptr || k == 0) return nullptr;
    ListNode* pFirst = pListHead;
    for(int i = 0; i < k - 1; ++i){
        if(pFirst->next != nullptr) pFirst = pFirst->next;
        else return nullptr;
    }
    ListNode* pSecond = pListHead;
    while(pFirst->next != nullptr){
        pFirst = pFirst->next;
        pSecond = pSecond->next;
    }
    return pSecond;
}