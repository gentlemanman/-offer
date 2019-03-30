//
// Created by zhaohan on 2019/2/15.
//
#include <iostream>
using namespace std;

int  NumberOf1(int n) {
    int count = 0;
    while(n){
        n = n & (n - 1);
        ++count;
    }
    return count;
}

int main(){
    cout<<NumberOf1(4);
    return 0;
}

