#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

void dfs(TreeNode* root, int target, vector<int>& tmp, vector<vector<int>>& ans){
    if(!root->left && !root->right){
        if(target == root->val){
            tmp.push_back(root->val);
            ans.push_back(tmp);
            tmp.pop_back();
        }
        return;
    }

    tmp.push_back(root->val);
    if(root->left) dfs(root->left, target-root->val, tmp, ans);
    if(root->right) dfs(root->right, target-root->val, tmp, ans);
    tmp.pop_back();
}

vector<vector<int>> FindPath(TreeNode* root, int target){
    vector<int> tmp;
    vector<vector<int>> ans;
    dfs(root, target, tmp, ans);
    return ans;
}


int main()
{
}
