#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, t=0; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i, t+=i;
    sort(v.begin(),v.end());
    ll res=0;
    for(int i=0;i<n;i++) t-=v[i], res+=v[i]*t;
    cout << res;
    return 0;
}