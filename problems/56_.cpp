#include <iostream>
#include <vector>
using namespace std;

bool is1(int num, int idx){
    num = num >> idx;
    return (num & 1);
}

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    if(data.size() < 2) return;
    int eor = 0;
    for(auto i : data)
        eor ^= i;
    int idx = 0;

    while((eor & 1) == 0 && (idx < 8 * sizeof(int))){
        eor = eor >> 1;
        idx++;
    }

    *num1 = 0, *num2 = 0;
    for(auto num : data){
        if(is1(num, idx))
            *num1 ^= num;
        else
            *num2 ^= num;
    }
}

int main()
{

}