//
// Created by zhaohan on 2019/2/9.
//
#include <iostream>
#include <vector>
using namespace std;

bool Find(int target, vector<vector<int>> array) {
        bool found = false;
        if(array.empty()) return found;
        int rows = array.size();
        int cols = array[0].size();
        int row = 0;
        int col = cols - 1;
        while(row < rows && col >= 0){
            if(array[row][col] == target){
                found = true;
                break;
            }
            if(array[row][col] > target) col--;
            else row++;
        }
        return found;
}

