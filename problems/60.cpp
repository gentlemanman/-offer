// 定义状态转移方程为f(n,k)表示n个骰子点数和为k时出现的次数：f(n,k)=f(n−1,k−1)+f(n−1,k−2)+f(n−1,k−3)+f(n−1,k−4)+f(n−1,k−5)+f(n−1,k−6)
// f(1,1)=f(1,2)=f(1,3)=f(1,4)=f(1,5)=f(1,6)=1
// https://www.cnblogs.com/wangkundentisy/p/9378886.html

#include <iostream>
#include <cstdlib>
#include <memory.h>
using namespace std;

void PrintProbability(int n){
    if(n < 1) return;
    int dp[n + 1][6 * n + 1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= 6; ++i)
        dp[1][i] = 1;

    for(int i = 2; i <= n; ++i){
        for(int j = i; j <= i * 6; ++j){
            dp[i][j] +=  dp[i - 1][j - 1] + dp[i - 1][j - 2] + dp[i - 1][j - 3] + dp[i - 1][j - 4] + dp[i - 1][j - 5] + dp[i - 1][j - 6];
        }
    }
    int sum = 0;
    for(int i = n; i <= 6 * n; ++i){
        sum += dp[n][i];
    }
    for(int i = n; i <= 6 * n; ++i){
        cout<<"s is "<< i <<", p is "<<dp[n][i] * 1.0 / sum<<endl;
    }
}
int main(){
    PrintProbability(1);
    return 0;
}