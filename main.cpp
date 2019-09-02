#include <iostream>
#include <vector>
#include <set>
using namespace std;

<<<<<<< HEAD
void fun(int *a, int *b){
    *a = *a - *b;
    *b = *a + *b;
    *a = *b - *a;
=======
void dfs(vector<int>& a, vector<int>& tmp, int idx, int m, set<int>& s){
    if(tmp.size() == m){
        for(int i = 1; i < tmp.size(); ++i){
            s.insert(tmp[i] - tmp[i - 1]);
        }
        return;
    }
    for(int i = idx; i < a.size(); ++i){
        tmp.push_back(a[idx]);
        dfs(a, tmp, idx + 1, m, s);
        tmp.pop_back();
    }
>>>>>>> 3bbf477b60e2f0fe353547ededd30990733ac72b
}

int main()
{
<<<<<<< HEAD

    string str;
    while(cin>>str){
        cout<<str;
    }

=======
    int n, m;
    cin>>n>>m;
    vector<int> a(n, 0);
    for(int i = 0; i < n; ++i){
        int t;
        cin>>t;
        a[i] = t;
    }
    vector<int> tmp;
    set<int> s;
    dfs(a, tmp, 0, m, s);
    cout<<*s.rbegin()<<endl;
    return 0;
>>>>>>> 3bbf477b60e2f0fe353547ededd30990733ac72b
}
