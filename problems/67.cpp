//
// Created by Administrator on 2019/5/4.
// 把字符串转换成整数

#include <iostream>
using namespace std;

enum Status{kValid = 0, kInValid};
int g_nStatus = kValid;
long long StrToIntCore(const char* cstr, bool minus){
    long long num = 0;
    while(*cstr != '\0'){
        if(*cstr >= '0' && *cstr <= '9'){
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*cstr - '0');
            if((!minus && num > 0x7fffffff) || (minus && num < (signed int)0x80000000)){
                num = 0;
                break;
            }
            cstr++;
        } else{
            num = 0;
            break;
        }
    }
    return num;
}
int StrToInt(string str) {
    g_nStatus = kInValid;
    long long num = 0;
    const char* cstr = str.c_str();
    if(cstr != NULL && *cstr != '\0'){
        bool minus = false;
        if(*cstr == '+'){
            cstr++;
        }
        else if(*cstr == '-'){
            minus = true;
            cstr++;
        }
        if(*cstr != '\0'){
            num = StrToIntCore(cstr, minus);
        }
    }
    return (int)num;
}



int main(){
    StrToInt("");
    return 0;
}

