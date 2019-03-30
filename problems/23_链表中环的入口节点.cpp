//
// Created by zhaohan on 2019/2/22.
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
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* meetingNode = MeetingNode(pHead);
        if(!meetingNode) return nullptr;
        // 统计环中节点的个数
        int count = 1;
        ListNode* pNode1 = meetingNode;
        while(pNode1->next != meetingNode){
            pNode1 = pNode1->next;
            ++count;
        }
        pNode1 = pHead;
        for(int i = 0; i < count; ++i){
            pNode1 = pNode1->next;
        }
        ListNode* pNode2 = pHead;
        while (pNode1 != pNode2){
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        return pNode1;
    }

private:
    ListNode* MeetingNode(ListNode* pHead)
    {
        if(!pHead) return nullptr;
        ListNode* pSlow = pHead;
        if(pHead->next == nullptr)
            return nullptr;
        ListNode* pFast = pHead->next;
        while(pSlow && pFast){
            if(pSlow == pFast)
                return pSlow;
            pSlow = pSlow->next;
            if(pFast->next)
                pFast = pFast->next->next;
        }
        return nullptr;
    }
};
