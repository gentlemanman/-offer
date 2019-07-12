#include <bits/stdc++.h>
using namespace std;
string LeftRotateString(string str, int n) {
    if(n > str.length() || n < 0)
        return "";
    reverse(str.begin(), str.begin() + n);
    reverse(str.begin() + n, str.end());
    reverse(str.begin(), str.end());
    return str;
}
