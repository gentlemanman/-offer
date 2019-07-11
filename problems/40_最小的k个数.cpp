#include <bits/stdc++.h>
using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> ans;
    if(input.size() <=0 || k <= 0) return ans;
    multiset<int> m;
    for(int i = 0; i < input.size(); ++i){
        if(m.size() < k){
            m.insert(input[i]);
        }
        else{
            auto a = m.rbegin();
            if(input[i] < *a){
                m.erase(*a);
                m.insert(input[i]);
            }
        }
    }
    for(auto i : m){
        ans.push_back(i);
    }
    return ans;
}

int main(){
    vector<int> input = {1, 2, 3, 4, 5, 6};
    vector<int> ans = GetLeastNumbers_Solution(input, 2);
    for(int i = 0; i < ans.size(); ++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}

