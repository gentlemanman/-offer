#include <bits/stdc++.h>
using namespace std;

int GetUglyNumber_Solution(int index) {
    if(index < 0) return 0;
    vector<int> uglys(index + 1, 1);
    uglys[0] = 1;
    int t2 = 0, t3 = 0, t5 = 0;
    for(int i = 1; i < index; ++i){
        uglys[i] = min(uglys[t2] * 2, min(uglys[t3] * 3, uglys[t5] * 5));
        while (uglys[i] >= uglys[t2] * 2) t2++;
        while (uglys[i] >= uglys[t3] * 3) t3++;
        while (uglys[i] >= uglys[t5] * 5) t5++;
    }
    return uglys[index - 1];
}

int main(){
    cout<<GetUglyNumber_Solution(3)<<endl;
    return 0;
}