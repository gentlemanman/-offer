//
// Created by zhaohan on 2019/2/12.
//
#include <iostream>
using namespace std;

int Fibonacci(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    int a = 0, b = 1;
    int ans = 0;
    for(int i = 2; i <= n; ++i){
        ans = a + b;
        a = b;
        b = ans;
    }
    return ans;
}
