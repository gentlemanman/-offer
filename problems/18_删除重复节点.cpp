//
// Created by zhaohan on 2019/2/16.
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
ListNode* deleteDuplication(ListNode* pHead)
{
    if(!pHead) return NULL;
    ListNode* pPre = NULL;
    ListNode* pCur = pHead;
    ListNode* pNext = NULL;
    while(pCur != NULL){
        // 当前节点和下一个节点相同
        if(pCur->next && pCur->val == pCur->next->val){
            pNext = pCur->next;
            while(pNext->next && pCur->val == pNext->next->val){
                pNext = pNext->next;
            }
            if(pCur == pHead) pHead = pNext->next;
            else pPre->next = pNext->next;
            pCur = pNext->next;
        }
        else{
            pPre = pCur;
            pCur = pCur->next;
        }
    }
    return pHead;
}

