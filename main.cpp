#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

void fun(int *a, int *b){
    *a = *a - *b;
    *b = *a + *b;
    *a = *b - *a;
}

int main()
{

    string str;
    while(cin>>str){
        cout<<str;
    }

}
