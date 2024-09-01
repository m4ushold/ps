#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M;

bool chk(ll m, vector<ll> &v) {
    ll t=M;
    for(ll i:v) {
        t-=m/i;
        if(t<=0) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    vector<ll> v(N);
    for(ll &i:v) cin >> i;
    ll s=1,e=*max_element(v.begin(),v.end()) * M;
    while(s+1<e) {
        ll m=(s+e)/2;
        if(chk(m, v)) e=m;
        else s=m;
    }
    cout << e;
    return 0;
}