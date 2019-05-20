#include <iostream>
#include <vector>
using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    vector<int> ans;
    if(array.empty()) return ans;
    int i = 0, j = array.size() - 1;
    while(i < j){
        int t = array[i] + array[j];
        if(t == sum){
            ans.push_back(array[i]);
            ans.push_back(array[j]);
            break;
        }
        else if(t < sum){
            i++;
        }
        else{
            j--;
        }
    }
    return ans;
}

