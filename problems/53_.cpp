#include <bits/stdc++.h>
using namespace std;

int First(vector<int>& data,int k){
    int begin = 0;
    int end = data.size() - 1;
    int mid = (begin + end) / 2;
    while(begin <= end){
        mid = (begin + end) / 2;
        if(data[mid] == k){
            if((mid - 1 >= 0 && data[mid - 1] != k) || mid == 0)
                return mid;
            else
                end = mid - 1;
        }
        else if(data[mid] < k)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int Last(vector<int>& data,int k){
    int begin = 0;
    int end = data.size() - 1;
    int mid = (begin + end) / 2;
    while(begin <= end){
        mid = (begin + end) / 2;
        if(data[mid] == k){
            if((mid + 1 <= data.size() -1 && data[mid + 1] != k) || mid == data.size() - 1)
                return mid;
            else
                begin = mid + 1;
        }
        else if(data[mid] < k)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int GetNumberOfK(vector<int> data ,int k) {
    if(data.empty()) return 0;
    int ans = 0;
    int f = First(data, k);
    int l = Last(data, k);
    if(f >=0 && l >= 0){
        ans = l - f + 1;
    }
    return ans;
}

int main(){
    vector<int> data = {1, 2, 2, 2, 4, 5};
    int ans = GetNumberOfK(data, 2);
    cout<<ans<<endl;
    return 0;
}