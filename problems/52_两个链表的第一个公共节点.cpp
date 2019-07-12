#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

int Len(ListNode* head){
    int len = 0;
    while (head){
        len++;
        head = head->next;
    }
    return len;
}

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    int l1 = Len(pHead1);
    int l2 = Len(pHead2);

    ListNode* longHead = pHead1;
    ListNode* shortHead = pHead2;
    if(l2 > l1){
        longHead = pHead2;
        shortHead = pHead1;
    }
    int offset = abs(l1 - l2);
    for(int i = 0; i < offset; ++i){
        longHead = longHead->next;
    }
    while (longHead && shortHead && shortHead != longHead){
        longHead = longHead->next;
        shortHead = shortHead->next;
    }
    return longHead;
}

