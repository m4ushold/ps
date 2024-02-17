#include <bits/stdc++.h>
using namespace std;
using ll=long long;

bool cmp(pair<ll,ll> a, pair<ll,ll> b) {
    auto [at,ak]=a;
    auto [bt,bk]=b;
    return min(at*ak, 5*ak) > min(at*bk,5*bk);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,l; cin >> n >> l;
    vector<pair<ll,ll>> v(n);
    for(auto &[t,k]:v) cin >> k >> t;
    sort(v.begin(),v.end(), cmp);

    ll res=0, p=0;
    for(auto [t,k]:v) {
        if(p+k*t > l) res+=p+k*t-l, p-=p+k*t-l;
        p+=k*t, res+=t;
        p-=max(0LL,min(k*t,5*k));
    }
    cout << res;
    return 0;
}