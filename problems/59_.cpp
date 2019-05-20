#include <bits/stdc++.h>
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> ans;
    if(size > num.size() || size < 1)
        return ans;
    deque<int> d;
    for(int i = 0; i < size; ++i){
        while(!d.empty() && num[i] >= num[d.back()])
            d.pop_back();
        d.push_back(i);
    }
    ans.push_back(num[d.front()]);

    for(int i = size; i < num.size(); ++i){
        while (!d.empty() && num[i] >= num[d.back()])
            d.pop_back();
        if(!d.empty() && d.front() <= (int)(i - size))
            d.pop_front();
        d.push_back(i);
        ans.push_back(num[d.front()]);
    }
    return ans;
}
