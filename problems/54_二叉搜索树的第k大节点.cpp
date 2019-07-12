#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL),right(NULL){}
};

TreeNode* KthNode(TreeNode* root, int k){
    // 数的非递归中序遍历
    if(root == nullptr || k <= 0) return nullptr;
    stack<TreeNode*> s;
    while (root || !s.empty()){
        while (root){
            s.push(root);
            root = root->left;
        }
        if(!s.empty()){
            if(--k == 0) return s.top();
            root = s.top()->right;
            s.pop();
        }
    }
    return nullptr;
}
