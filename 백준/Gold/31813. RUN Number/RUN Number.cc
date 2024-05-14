#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll f(ll k) {
    string s=to_string(k);
    ll n=s.size(), t=stoll(string(n,s[0]));
    if(t > k) {
        if(s[0]=='1') t=stoll(string(n-1,'9'));
        else t=stoll(string(n,s[0]-1));
    }
    return t;
}

void sol() {
    ll n,k; cin >> n >> k;
    vector<ll> v;
    while(k) {
        ll t=f(k);
        v.push_back(t), k-=t;
    }
    cout << v.size() << "\n";
    for(ll i:v) cout << i << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}