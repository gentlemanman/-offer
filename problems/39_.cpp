#include <bits/stdc++.h>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
    map<int, int> m;
    for(int i = 0; i < numbers.size(); ++i){
        m[numbers[i]]++;
    }
    int ans = 0;
    for(int i = 0; i < numbers.size(); ++i){
        if(m[numbers[i]] > numbers.size() / 2){
            ans = numbers[i];
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> numbers = {0, 1, 2, 1, 1};
    int ans = MoreThanHalfNum_Solution(numbers);
    cout<<ans<<endl;
    return 0;
}

