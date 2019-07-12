// 扑克牌中的顺子
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool IsContinuous( vector<int> numbers ) {
    if (numbers.size() != 5) return false;
    sort(numbers.begin(), numbers.end());
    // count 0
    int count_0 = 0;
    int i = 0;
    while(numbers[i] == 0){
        count_0++;
        i++;
    }
    // sum gap
    int gap = 0;
    while(i < numbers.size() - 1){
        if(numbers[i] == numbers[i + 1])
            return false;
        gap += numbers[i + 1] - numbers[i] - 1;
        i++;
    }
    if(gap == 0 && count_0 == 4) return true;
    return (gap == count_0) ? true : false;
}

int main(){
    return 0;
}
