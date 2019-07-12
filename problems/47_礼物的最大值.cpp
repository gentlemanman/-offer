#include <bits/stdc++.h>
using namespace std;

int max_gift(vector<vector<int>> gifts){
    if(gifts.empty()) return 0;
    int rows = gifts.size();
    int cols = gifts[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            int up = 0;
            if(i > 0){
                up = dp[i - 1][j];
            }
            int left = 0;
            if(j > 0){
                left = dp[i][j - 1];
            }
            dp[i][j] = max(left, up) + gifts[i][j];
        }
    }
    return dp[rows - 1][cols - 1];
}

int main()
{
    vector<vector<int>> gifts = {{1, 10, 3, 8}, {12, 2, 9, 6}, {5, 7, 4, 11}, {3, 7, 16, 5}};
    int ans = max_gift(gifts);
    cout<<ans<<endl;
    return 0;
}
