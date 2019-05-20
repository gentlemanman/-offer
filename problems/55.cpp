#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {}
};

int TreeDepth(TreeNode* pRoot)
{
    if(pRoot == nullptr) return 0;
    int left = TreeDepth(pRoot->left);
    int right = TreeDepth(pRoot->right);
    return left > right ? left + 1 : right + 1;
}