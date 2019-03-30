//
// Created by zhaohan on 2019/3/2.
//
#include <iostream>
#include <vector>
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
    vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
    	vector<vector<int>> ans;
		if(!root) return ans;
		vector<int> tmp;
		dfs(root, expectNumber, tmp, ans);
		return ans;
    }

private:
    void dfs(TreeNode* node, int expectNumber, vector<int> &tmp, vector<vector<int>> &ans){

        if (node->left == NULL && node->right == NULL) {
            if(node->val == expectNumber) {
                tmp.push_back(node->val);
                ans.push_back(tmp);
                tmp.pop_back();
            }
            return;
        }
        tmp.push_back(node->val);

        if(node->left) dfs(node->left, expectNumber - node->val, tmp, ans);
        if(node->right) dfs(node->right, expectNumber - node->val, tmp, ans);

        tmp.pop_back();
    }
};

int main()
{
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(7);
	root->right = new TreeNode(12);
	Solution s;
	vector<vector<int>> ans = s.FindPath(root, 22);


	for(int i = 0; i < ans.size(); ++i){
		for(int j = 0; j < ans[i].size(); ++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
