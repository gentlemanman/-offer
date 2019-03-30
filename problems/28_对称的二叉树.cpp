//
// Created by zhaohan on 2019/2/23.
//
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return dfs(pRoot, pRoot);
    }

private:
    bool dfs(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot1 == nullptr && pRoot2 == nullptr) return true;
        if(pRoot1 == nullptr || pRoot2 == nullptr) return false;
        if(pRoot1->val != pRoot2->val) return false;
        return dfs(pRoot1->left, pRoot2->right) &&
            dfs(pRoot1->right, pRoot2->left);
    }
};
