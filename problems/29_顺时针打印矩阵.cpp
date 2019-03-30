//
// Created by zhaohan on 2019/2/24.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ans;
        if(matrix.empty()) return ans;
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
        while(left <= right && top <= bottom){
            // 左右
            for(int i = left; i <= right; ++i)
                ans.push_back(matrix[top][i]);
            // 上下
            if(top < bottom){
                for(int i = top + 1; i <= bottom; ++i)
                    ans.push_back(matrix[i][right]);
            }
            // 右左
            if(top < bottom && left < right){
                for(int i = right - 1; i >= left; --i)
                    ans.push_back(matrix[bottom][i]);
            }
            // 下上
            if(top < bottom - 1 && left < right){
                for(int i = bottom - 1; i >= top + 1; --i)
                    ans.push_back(matrix[i][left]);
            }
            ++left, --right, ++top, --bottom;
        }
        return ans;
    }
};

