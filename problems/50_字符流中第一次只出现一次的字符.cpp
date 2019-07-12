#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Solution() : index(0){
        times = vector<int>(256, -1);
    }
    //Insert one char from stringstream
    void Insert(char ch)
    {
        if(times[ch] == -1){
            times[ch] = index;
        }
        else if(times[ch] >= 0){
            times[ch] = -2;
        }
        index++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int idx = index;
        char ans = '#';
        for(int i = 0; i < times.size(); ++i){
            if(times[i] >= 0){
                if(times[i] < idx){
                    idx = times[i];
                    ans = i;
                }
            }
        }
        return ans;
    }

private:
    int index;
    vector<int> times;
};
