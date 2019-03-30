//
// Created by zhaohan on 2019/2/13.
//

#include <iostream>
using namespace std;

bool dfs(char* matrix, int rows, int cols, char* str, int i, int j, int idx, bool* visited){
    if(str[idx] == '\0') return true;
    if(i >= rows || j >= cols || i < 0 || j < 0 || matrix[i * cols + j] != str[idx] || visited[i * cols + j]) return false;
    visited[i * cols + j] = true;
    bool ans = dfs(matrix, rows, cols, str, i - 1, j, idx + 1, visited) ||
            dfs(matrix, rows, cols, str, i + 1, j, idx + 1, visited) ||
            dfs(matrix, rows, cols, str, i, j - 1, idx + 1, visited) ||
            dfs(matrix, rows, cols, str, i, j + 1, idx + 1, visited);
    visited[i * cols + j] = false;
    return ans;
}

bool hasPath(char* matrix, int rows, int cols, char* str) {
    if(matrix == nullptr || str == nullptr) return false;
    bool* visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            if(dfs(matrix, rows, cols, str, i, j, 0, visited)) return true;
        }
    }
    return false;
}
