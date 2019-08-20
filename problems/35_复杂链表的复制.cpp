//
// Created by zhaohan on 2019/3/3.
//
#include <iostream>
using namespace std;
struct RandomListNode{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x): label(x), next(NULL), random(NULL){}
};

class Solution{
public:
    // 第一步：复制label和next,a->a'->b->b'.
    void CloneNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        while(pNode != NULL){
            RandomListNode* pCloned = new RandomListNode(0);
            pCloned->label = pNode->label;
            pCloned->next = pNode->next;
            pCloned->random = NULL;

            pNode->next = pCloned;
            pNode = pCloned->next;
        }
    }
    //第二步：处理random
    void ConnectSiblingNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        while(pNode != NULL){
            RandomListNode* pCloned = pNode->next;
            if(pNode->random != NULL) pCloned->random = pNode->random->next;
            pNode = pCloned->next;
        }
    }
    //第三步：将一个链表拆成两个
    RandomListNode* ReconnectNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        RandomListNode* pCloneHead = NULL;
        RandomListNode* pCloneNode = NULL;
        if(pNode != NULL){
            pCloneHead = pCloneNode = pNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }
        while(pNode != NULL){
            pCloneNode->next = pNode->next;
            pCloneNode = pCloneNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }
        return pCloneHead;
    }
    RandomListNode* Clone(RandomListNode* pHead){
        CloneNodes(pHead);
        ConnectSiblingNodes(pHead);
        return ReconnectNodes(pHead);
    }
};

class CopyListWithRandom {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        map<RandomListNode*, RandomListNode*> myMap;
        RandomListNode* cur = pHead;
        while(cur != NULL){
            myMap.insert(pair<RandomListNode*, RandomListNode*>(cur, new RandomListNode(cur->value)));
            cur = cur->next;
        }
        cur = pHead;
        while(cur != NULL){
            myMap[cur]->next = myMap[cur->next];
            myMap[cur]->random = myMap[cur->random];
            cur = cur->next;
        }

        return myMap[pHead];
    }
};
