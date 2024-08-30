#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<pair<ll,ll>> v(n);
    for(auto &[i,j]:v) cin >> i >> j;
    sort(v.begin(),v.end(), [](pair<ll,ll> a, pair<ll,ll> b){
        ll aa=a.second-a.first, bb=b.second-b.first;
        if(aa >= 0 && bb < 0) return true;
        if(aa < 0 && bb >= 0) return false;
        if(aa < 0) return a.second > b.second;
        return a.first < b.first;
    });

    ll cap=0, buy=0;
    for(auto [i,j]:v) {
        if(cap < i) buy+=i-cap, cap=j;
        else cap+=j-i;
    }
    cout << buy;
    return 0;
}