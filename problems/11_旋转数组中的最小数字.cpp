//
// Created by zhaohan on 2019/2/13.
//

#include <iostream>
#include <vector>
using namespace std;

int help(vector<int> rotateArray, int left, int right){
    int min = rotateArray[left];
    for(int i = left + 1; i <= right; ++i)
        if(rotateArray[i] < min) min = rotateArray[i];
    return min;
}

int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.empty()) return 0;
    int left = 0, right = rotateArray.size() - 1;
    int mid = (left + right) / 2;

    while(rotateArray[left] >= rotateArray[right]){
        if(right - left == 1) return rotateArray[right];
        mid = (left + right) / 2;
        if(rotateArray[mid] == rotateArray[left] && rotateArray[left] == rotateArray[right]){
            return help(rotateArray, left, right);
        }
        if(rotateArray[mid] >= rotateArray[left]) left = mid;
        else if(rotateArray[mid] <= rotateArray[right]) right = mid;
    }
    return rotateArray[mid];
}