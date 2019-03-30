//
// Created by zhaohan on 2019/2/20.
//
#include <iostream>
using namespace std;
class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string == nullptr) return false;
        bool numeric = scanInteger(&string);
        if(*string == '.'){
            ++string;
            numeric = scanUnsignedInteger(&string) || numeric;
        }
        if(*string == 'e' || *string == 'E'){
            ++string;
            numeric = numeric && scanInteger(&string);
        }
        return numeric && *string == '\0';
    }

private:
    bool scanInteger(char** string){
        if(**string == '+' || **string == '-') ++(*string);
        return scanUnsignedInteger(string);
    }
    bool scanUnsignedInteger(char** string){
        const char* before = *string;
        while(**string != '\0' && **string >= '0' && **string <= '9')
            ++(*string);
        return *string > before;
    }
};

int main(){
    Solution s;
    //123.45e+6
    char string[] = {'1', '2', '3', '.', '4', '5', 'e', '+', '6', '\0'};
    cout<<s.isNumeric(string)<<endl;
    return 0;
}
