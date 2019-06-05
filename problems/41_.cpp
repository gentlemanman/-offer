#include <bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if((small.size()+large.size()) % 2 == 0){
            if(!large.empty() && num >= *large.begin()){
                large.insert(num);
                num = *large.begin();
                large.erase(large.begin());
            }
            small.insert(num);
        }
        else{
            if(!small.empty() && num <= *small.rbegin()){
                small.insert(num);
                num = *small.rbegin();
                small.erase((--small.end()));
            }
            large.insert(num);
        }
    }

    double findMedian() {
        int size = small.size() + large.size();
        if(size % 2 == 0){
            return (*small.rbegin() + *large.begin()) / 2.0;
        }
        else{
            return *small.rbegin();
        }
    }

private:
    multiset<int> small, large;
};
