#include <bits/stdc++.h>
using namespace std;

long Merge(vector<int>& data, vector<int>& copy, int begin, int end){
    if(begin == end){
        copy[begin] = data[end];
        return 0;
    }
    int mid = (end + begin) >> 1;
    long left = Merge(copy, data, begin, mid);
    long right = Merge(copy, data, mid + 1, end);

    int i = mid;
    int j = end;
    int idx_copy = end;
    long count = 0;
    while(i >= begin && j >= mid + 1){
        if(data[i] > data[j]){
            copy[idx_copy--] = data[i--];
            count += j - mid;
        }
        else{
            copy[idx_copy--] = data[j--];
        }
    }
    while(i >= begin) copy[idx_copy--] = data[i--];
    while(j >= mid + 1) copy[idx_copy--] = data[j--];
    return left + right + count;
}

int InversePairs(vector<int> data) {
    if(data.size() == 0) return 0;
    // 归并排序的辅助排序数组
    vector<int> copy = data;
    return Merge(data, copy, 0, data.size() - 1) % 1000000007;
}
