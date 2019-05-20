#include <bits/stdc++.h>
using namespace std;

int FirstNotRepeatingChar(string str) {
    int ans = -1;
    if(str.empty()) return ans;
    unordered_map<char, int> m;
    for(int i = 0; i < str.length(); ++i){
        m[str[i]]++;
    }
    for(int i = 0; i < str.length(); ++i){
        if(m[str[i]] == 1){
            ans = i;
            break;
        }
    }
    return ans;
}
