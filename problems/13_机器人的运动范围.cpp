//
// Created by zhaohan on 2019/2/13.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold <= 0 || rows <=0 || cols <= 0) return 0;
        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows*cols);
        int ans = dfs(threshold, rows, cols, 0, 0, visited);
        delete[] visited;
        return ans;
    }

private:
    int dfs(int threshold, int rows, int cols, int i, int j, bool *visited){
        int count = 0;
        if(check(threshold, rows, cols, i, j, visited)){
            visited[i * cols + j] = true;
            count = 1 + dfs(threshold, rows, cols, i + 1, j, visited) +
                    dfs(threshold, rows, cols, i - 1, j, visited) +
                    dfs(threshold, rows, cols, i, j + 1, visited) +
                    dfs(threshold, rows, cols, i, j - 1, visited);
        }
        return count;
    }

    bool check(int threshold, int rows, int cols, int i, int j, bool *visited){
        if(i >=0 && j >= 0 && i < rows && j < cols
        && getSum(i) + getSum(j) <= threshold
        && !visited[i * cols + j]) return true;
        return false;
    }

    int getSum(int n){
        int sum = 0;
        while(n > 0){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};

int main()
{
    Solution s;
    int ans = s.movingCount(10, 5, 5);
    cout<<ans<<endl;
    return ans;
}