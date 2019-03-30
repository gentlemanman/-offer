//
// Created by zhaohan on 2019/2/20.
//
#include <iostream>
using namespace std;
bool matchCore(char* str, char* pattern)
{
    if(*str == '\0' && *pattern == '\0') return true;
    if(*str != '\0' && *pattern == '\0') return false;
    if(*(pattern + 1) == '*'){
        if(*str == *pattern || (*pattern == '.' && *str != '\0')){
            return matchCore(str + 1, pattern) ||
                matchCore(str, pattern + 2) ||
                matchCore(str + 1, pattern + 2);
        }
        else{
            return matchCore(str, pattern + 2);
        }
    }
    if(*str == *pattern || (*pattern == '.' && *str != '\0')){
        return matchCore(str + 1, pattern + 1);
    }
    return false;
}
bool match(char* str, char* pattern)
{
    if(str == nullptr || pattern == nullptr) return false;
    return matchCore(str, pattern);
}

int main(){
    char str[] =     {'a', 'b', 'c', '\0'};
    char pattern[] = {'a', 'b', 'c', '\0'};
    cout<<match(str, pattern)<<endl;
    return 0;
}

