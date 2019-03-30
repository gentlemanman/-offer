//
// Created by zhaohan on 2019/3/7.
//
#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

void ConvertCore(TreeNode* root, TreeNode*& prev){
    if(!root) return;
    TreeNode* cur = root;
    if(cur->left)
        ConvertCore(cur->left, prev);
    cur->left = prev;
    if(prev){
        (prev)->right = cur;
    }

    prev = cur;
    if(cur->right)
        ConvertCore(cur->right, prev);
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
    TreeNode* prev = NULL;
    ConvertCore(pRootOfTree, prev);
    while(pRootOfTree && pRootOfTree->left){
        pRootOfTree = pRootOfTree->left;
    }
    return pRootOfTree;
}

int main() {
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(0);
    node->right = new TreeNode(2);
    TreeNode *t = Convert(node);
    cout << t->val << endl;
    cout << t->right->val << endl;
    cout << t->right->right->val << endl;
    return 0;
}