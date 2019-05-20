#include <bits/stdc++.h>
using namespace std;

int GetTranslationCount(int number){
    if(number < 0) return 0;
    string str = to_string(number);
    int len = str.length();
    vector<int> dp(len, 0);
    int count = 0;
    for(int i = len - 1; i >= 0; --i){
        if(i < len - 1) count = dp[i + 1];
        if(i == len - 1) count = 1;
        if(i < len - 1){
            int n1 = str[i] - '0';
            int n2 = str[i + 1] - '0';
            int n = n1 * 10 + n2;
            if(n >= 10 && n <= 25){
                if(i < len - 2) count += dp[i + 2];
                if(i == len - 2) count += 1;
            }
        }
        dp[i] = count;
    }
    return dp[0];
}
int main(){
    cout<<GetTranslationCount(12258)<<endl;
    return 0;
}
