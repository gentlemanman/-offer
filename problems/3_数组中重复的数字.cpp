//
// Created by zhaohan on 2019/2/9.
//

#include <iostream>
using namespace std;

bool duplicate(int numbers[], int length, int *duplication){
    if(numbers == nullptr || length <= 0) return false;
    for(int i = 0; i < length; ++i){
        if(numbers[i] < 0 || numbers[i] > length - 1) return false;
    }
    for(int i = 0; i < length; ++i){
        while(numbers[i] != i){
            //swap(numbers[i], numbers[tmp]);
            int tmp = numbers[i];
            if(numbers[i] == numbers[tmp]){
                *duplication = numbers[i];
                return true;
            }
            numbers[i] = numbers[tmp];
            numbers[tmp] = tmp;
        }
    }
    return false;
}

