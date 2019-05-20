// 圆圈中最后的数字
#include <iostream>
#include <list>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
    if(n < 0 || m <= 0) return -1;
    list<int> l;
    for(int i = 0; i < n; ++i)
        l.push_back(i);
    auto iter = l.begin();
    while(l.size() > 1){
        for(int i = 1; i < m; ++i){
           ++iter;
           if(iter == l.end())
               iter = l.begin();
        }
        auto next = ++iter;
        if(next == l.end())
            next = l.begin();
        --iter;
        l.erase(iter);
        iter = next;
    }
    return *iter;
}
