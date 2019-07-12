#include <bits/stdc++.h>
using namespace std;
string ReverseSentence(string str) {
    reverse(str.begin(), str.end());

    int start = 0;
    for(int i = 0; i < str.length(); ++i){
        if(str[i] == ' '){
            reverse(str.begin() + start, str.begin() + i);
            start = i + 1;
        }
    }
    reverse(str.begin() + start, str.end());
    return str;
}

int main(){
    cout<<ReverseSentence("ab  cde cde")<<endl;
    return 0;
}
