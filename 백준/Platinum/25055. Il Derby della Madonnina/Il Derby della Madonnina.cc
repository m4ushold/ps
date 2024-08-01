#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    ll T[1<<19], sz=1<<18;
    void update(int v, ll x) {
        v|=sz, T[v]=max(T[v],x);
        while(v>>=1) T[v]=max(T[v*2],T[v*2+1]);
    }
    ll query(int l, int r) {
        ll res=0;
        for(l|=sz,r|=sz ; l<=r ; l/=2,r/=2) {
            if(l&1) res=max(res,T[l++]);
            if(~r&1) res=max(res,T[r--]);
        }
        return res;
    }
} seg;

ll N, V, DP[202020], D2[202020];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> V;
    vector<ll> t(N),a(N);
    for(ll &i:t) cin >> i;
    for(ll &i:a) cin >> i;

    vector<pair<ll,ll>> v;
    for(int i=0;i<N;i++) if(V*t[i]>=abs(a[i])) v.push_back({V*t[i]-a[i], V*t[i]+a[i]});
    sort(v.begin(),v.end());

    vector<ll> b, tmp;
    for(auto i:v) b.push_back(i.second), tmp.push_back(i.second);
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    for(ll &i:b) i=lower_bound(tmp.begin(),tmp.end(),i)-tmp.begin();
    
    for(int i=0;i<b.size();i++) {
        DP[i]=seg.query(0, b[i])+1;
        seg.update(b[i], DP[i]);
    }
    cout << *max_element(DP, DP+N);
    return 0;
}