#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    int s=accumulate(v.begin(),v.end(),0);
    for(int i=0;i<n;i++) if(s-v[i] == v[i]) {cout << i+1; return 0;}
    return 0;
}