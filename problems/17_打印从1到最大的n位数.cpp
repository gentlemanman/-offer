//
// Created by zhaohan on 2019/2/16.
//
#include <iostream>
using namespace std;

void PrintNumber(char* number){
    bool isBeginning0 = true;
    int length = strlen(number);
    for(int i = 0; i < length; ++i){
        if(isBeginning0 && number[i] != '0')
            isBeginning0 = false;
        if(!isBeginning0)
            printf("%c", number[i]);
    }
    printf("\t");
}

bool Increment(char* number){
    bool isOverflow = false;
    int takeOver = 0;
    int length = strlen(number);
    for(int i = length - 1; i >= 0; --i){
        int sum = number[i] - '0' + takeOver;
        if(i == length - 1) sum++;
        if(sum >= 10){
            if(i == 0){
                isOverflow = true;
            }
            else{
                sum -= 10;
                takeOver = 1;
                number[i] = '0' + sum;
            }
        }
        else{
            number[i] = sum + '0';
            break;
        }
    }
    return isOverflow;
}

void Print1ToMaxOfNDigits(int n){
    if(n <= 0) return;
    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';
    while(!Increment(number)){
        PrintNumber(number);
    }
    delete[] number;
}

int main(){
    Print1ToMaxOfNDigits(2);
    return 0;
}

