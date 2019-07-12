#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {}
};

bool IsBalanced_Solution(TreeNode* pRoot, int& depth) {
    if(pRoot == nullptr){
        depth = 0;
        return true;
    }
    int left, right;
    if(IsBalanced_Solution(pRoot->left, left) && IsBalanced_Solution(pRoot->right, right)){
        int diff = left - right;
        if(diff <= 1 && diff >= -1){
            depth = 1 + (left > right ? left : right);
            return true;
        }
    }
    return false;
}

bool IsBalanced_Solution(TreeNode* pRoot){
    int depth = 0;
    return IsBalanced_Solution(pRoot, depth);
}

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout<<IsBalanced_Solution(root)<<endl;
    return 0;
}
