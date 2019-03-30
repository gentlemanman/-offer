//
// Created by zhaohan on 2019/2/15.
//
#include <iostream>
using namespace std;
class Solution {
public:
    double Power(double base, int exponent) {
        if(equal(base, 0.0)) return 0.0;
        unsigned int absexponent = 0;
        if(exponent > 0) absexponent = (unsigned int)exponent;
        else absexponent = (unsigned int)(-exponent);
        double ans = PowerWithUnsignedExponent(base, absexponent);
        if(exponent < 0) ans = 1.0 / ans;
        return ans;
    }

private:
    bool equal(double n1, double n2){
        if((n1 - n2) > -1e-7 && (n1 - n2) < 1e-7) return true;
        return false;
    }
    double PowerWithUnsignedExponent(double base, unsigned int exponent){
        if(exponent == 0) return 1;
        if(exponent == 1) return base;
        double result = PowerWithUnsignedExponent(base, exponent >> 1);
        result *= result;
        if(exponent & 0x1 == 1) result *= base;
        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.Power(2.0, 4)<<endl;
    return 0;
}
