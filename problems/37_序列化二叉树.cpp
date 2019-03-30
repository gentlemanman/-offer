//
// Created by zhaohan on 2019/3/8.
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
class Solution{
public:
    char *Serialize(TreeNode* root){
        if(!root) return NULL;
        string str;
        SerializeCore(root, str);
        int length = str.length();
        char* res = new char[length + 1];
        for(int i = 0; i < length; ++i){
            res[i] = str[i];
        }
        res[length] = '\0';
        return res;
    }
    void SerializeCore(TreeNode* root, string& str){
        if(!root){
            str += '#';
            str += ',';
            return;
        }
        string tmp = to_string(root->val);
        str += tmp;
        str += ',';
        SerializeCore(root->left, str);
        SerializeCore(root->right, str);
    }

    TreeNode* Deserialize(char* str){
        if(!str) return NULL;
        string s(str);
        TreeNode* res = DeserializeCore(s);
        return res;
    }
    TreeNode* DeserializeCore(string& s){
        if(s.empty()){
            return NULL;
        }
        if(s[0] == '#'){
            s = s.substr(2);
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(s));

        s = s.substr(s.find_first_of(',') + 1);
        root->left = DeserializeCore(s);
        root->right = DeserializeCore(s);
        return root;
    }
};


