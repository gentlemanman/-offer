//
// Created by zhaohan on 2019/2/9.
//
#include <iostream>
using namespace std;

void replaceSpace(char *str, int length) {
    if(str == nullptr || length <= 0) return ;
    int numOfBlank = 0;
    int orignalLength = 0;
    // 计算空格数
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == ' ') ++numOfBlank;
        orignalLength++;
        ++i;
    }
    // 计算新的字符串长度
    int newLength = orignalLength + 2 * numOfBlank;
    // 从尾到头开始复制字符串, 包括'\0'
    int idxOfOriginal = orignalLength;
    int idxOfNew = newLength;
    while(idxOfOriginal >= 0 && idxOfOriginal < idxOfNew){
        if(str[idxOfOriginal] == ' '){
            str[idxOfNew--] = '0';
            str[idxOfNew--] = '2';
            str[idxOfNew--] = '%';
        }
        else{
            str[idxOfNew--] = str[idxOfOriginal];
        }
        idxOfOriginal--;
    }
}

int main()
{
    char *str = new char[10];
    strcpy(str, "12 3");
    replaceSpace(str, 10);
    for(int i = 0; i < 10; ++i){
        cout<<str[i]<<endl;
    }
    return 0;
}



