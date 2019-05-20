#include <bits/stdc++.h>
using namespace std;

int CountN(int n){
    // 计算n位数共有多少个？
    if(n == 1) return 10;
    return 9 * pow(10, n-1);
}

int digitAtIndex(int index){
    if(index < 0) return -1;
    int n = 1;
    while(true){
        if(CountN(n) * n > index){
            break;
        }
        index -= CountN(n) * n;
        n++;
    }
    // 在n位数中
    int begin = (n == 1) ? 0 : pow(10, n - 1);
    int a = index / n;
    int b = index % n;
    return to_string(begin + a)[b] - '0';
}

int main(){
    cout<<digitAtIndex(1001)<<endl;
    return 0;
}

