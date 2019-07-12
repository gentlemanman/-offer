//
// Created by Administrator on 2019/5/2.
//
#include <iostream>
using namespace std;



class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        // &&就是逻辑与，逻辑与有个短路特点，前面为假，后面不计算。即递归终止条件
        ans && (ans += Sum_Solution(n - 1));
        return ans;
    }
};
int main()
{
    Solution s;
    cout<<s.Sum_Solution(1)<<endl;

}
