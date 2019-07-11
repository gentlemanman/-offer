#include <bits/stdc++.h>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
    int max = INT_MIN;
    int sum = 0;
    for(int i = 0; i < array.size(); ++i){
        sum += array[i];
        if(sum > max){
            max = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    return max;
}

int main()
{
    vector<int> array = {-2,-8,-1,-5,-9};
    int ans = FindGreatestSumOfSubArray(array);
    cout<<ans<<endl;
    return 0;
}
