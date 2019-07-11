#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(string& str, int begin, vector<string>& ans){
    if(begin == str.length()) {
        ans.push_back(str);
        return;
    }

    for(int i = begin; i < str.length(); ++i){
        if(i != begin && str[begin] == str[i]) continue;
        swap(str[begin], str[i]);
        dfs(str, begin + 1, ans);
        swap(str[begin], str[i]);
    }
}

vector<string> Permutation(string str) {
    vector<string> ans;
    if(str.empty()) return ans;
    int idx = 0;
    dfs(str, idx, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<string> ans = Permutation("aa");
    for(auto i : ans)
        cout<<i<<endl;
    cout<<"½áÊø"<<endl;
    return 0;
}
