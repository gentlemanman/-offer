//
// Created by zhaohan on 2019/2/11.
//

#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
    if(!pNode) return NULL;
    TreeLinkNode* pNext = NULL;
    if(pNode->right != NULL){
        TreeLinkNode* pRight = pNode->right;
        while(pRight->left != NULL){
            pRight = pRight->left;
        }
        pNext = pRight;
    }
    else if(pNode->next != NULL){
        TreeLinkNode* pCur = pNode;//当前节点
        TreeLinkNode* pPar = pNode->next;//父节点
        while(pPar != NULL && pCur == pPar->right){
            pCur = pPar;
            pPar = pCur->next;
        }
        pNext = pPar;
    }
    return pNext;
}