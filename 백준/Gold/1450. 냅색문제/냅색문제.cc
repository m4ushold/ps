#include <bits/stdc++.h>
using namespace std;
using ll=long long;

map<ll,ll> f(vector<ll> &v) {
    map<ll,ll> res;
    for(int i=0;i<1<<v.size();i++) {
        ll sum=0;
        for(int j=0;j<v.size();j++) if((i>>j) & 1) sum+=v[j];
        res[sum]++;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,c; cin >> n >> c;
    vector<ll> a(n/2), b(n+1>>1);
    for(ll &i:a) cin >> i;
    for(ll &i:b) cin >> i;
    auto aa = f(a), bb = f(b);
    vector<pair<ll,ll>> aaa(aa.begin(),aa.end()), bbb(bb.begin(),bb.end());

    for(int i=1;i<bbb.size();i++) bbb[i].second += bbb[i-1].second;
    ll ans=0;
    for(auto [x,cnt]:aaa) {
        if(c-x < 0) continue;
        auto it = upper_bound(bbb.begin(),bbb.end(),make_pair(c-x,LLONG_MAX));
        it--;
        ans += cnt * (*it).second;
    }
    cout << ans;
    return 0;
}