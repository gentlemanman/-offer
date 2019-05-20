#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> FindContinuousSequence(int sum) {
    vector<vector<int>> ans;
    if(sum <= 2) return ans;
    int i = 1, j = 2;
    while(i < j && j < sum){
        int tmp = (j - i + 1) * (i + j) / 2;
        if(tmp == sum){
            vector<int> out;
            for(int k = i; k <=j; ++k) out.push_back(k);
            ans.push_back(out);
            j++;
        }
        else if(tmp < sum){
            j++;
        }
        else{
            i++;
        }
    }
    return ans;
}
