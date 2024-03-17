#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll diff(vector<pair<int,int>> &v, int b) {
    ll a=1,c=0;
    for(int i=0;i<v.size();i++) if((b>>i)&1) a*=v[i].first, c+=v[i].second;
    return abs(a-c);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(auto &[i,j]:v) cin >> i >> j;
    ll mn=1e9;
    for(int i=1;i<1<<n;i++) mn=min(mn,diff(v,i));
    cout << mn;
    return 0;
}