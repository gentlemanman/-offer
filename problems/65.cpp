//
// Created by Administrator on 2019/5/4.
// 不用加减乘除做加法
#include <iostream>
using namespace std;

int Add(int num1, int num2)
{
    int sum = num1^num2;
    int carry = (num1&num2)<<1;
    while(carry != 0){
        num1 = sum;
        num2 = carry;
        sum = num1^num2;
        carry = (num1&num2)<<1;
    }
    return sum;
}