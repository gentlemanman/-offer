#include <bits/stdc++.h>
using namespace std;

static bool compare(int a, int b){
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    return s1 < s2;
}

string PrintMinNumber(vector<int> numbers) {
    string ans = "";
    if(numbers.empty()) return ans;
    sort(numbers.begin(), numbers.end(), compare);
    for(int i = 0; i < numbers.size(); ++i){
        ans += to_string(numbers[i]);
    }
    return ans;
}


