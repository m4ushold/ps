#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v(10);
    map<int,int> m;
    for(int &i:v) cin >> i, m[i]++;
    int mx=0,a=1;
    for(auto [i,j]:m) if(mx<j) mx=j, a=i;
    cout << accumulate(v.begin(),v.end(),0)/10 << " " << a;
    return 0;
}