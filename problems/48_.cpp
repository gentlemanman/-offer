#include <bits/stdc++.h>
using namespace std;

int longestSubstringWithoutDuplication(string str){
    int max_len = 0;
    if(str.empty()) return max_len;
    int cur_len = 0;
    vector<int> postion(str.size(), -1);
    for(int i = 0; i < str.size(); ++i){
        int pre_idx = postion[str[i] - 'a'];
        if(pre_idx < 0 || i - pre_idx > cur_len ){
            cur_len++;
        }
        else{
            cur_len = i - pre_idx;
        }
        if(cur_len > max_len){
            max_len = cur_len;
        }
        postion[str[i] - 'a'] = i;
    }
    return max_len;
}

int main(){
    int ans = longestSubstringWithoutDuplication("arabcacfr");
    cout<<ans<<endl;
    return 0;

}