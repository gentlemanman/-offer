//
// Created by zhaohan on 2019/2/21.
//
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
void reOrderArray(vector<int> &array) {
    if(array.empty()) return;
    deque<int> d;//定义双向队列
    for(int i = 0; i < array.size(); ++i){
        //从后向前遍历将奇数插入队头
        if((array[array.size() - 1 - i] & 0x1) == 1) d.push_front(array[array.size() - 1 - i]);
        //从前向后遍历将偶数插入队尾
        if((array[i] & 0x1) == 0) d.push_back(array[i]);
    }
    array.assign(d.begin(), d.end());
}
int main()
{
    vector<int> array = {1, 2, 3, 4, 5, 6, 7};
    reOrderArray(array);
    for(auto i : array) cout<<i<<endl;
    return 0;
}
