#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, A[202], B[202];

ll f(ll l, ll r) {
    // l<=r ? l-r : 1-r,l-n
    int m=M;
    if(l<=r) m-=min(r-1,N-l+1);
    else m-=min(r-1,N-l+1)*2 + max(r-1,N-l+1);

    priority_queue<pair<ll,ll>> pq;
    if(l<=r) for(int i=l;i<=r;i++) pq.push({A[i],i});
    else {
        for(int i=1;i<=r;i++) pq.push({A[i],i});
        for(int i=l;i<=N;i++) pq.push({A[i],i});
    }

    ll res=0;
    while(pq.size() && m-->0) {
        auto [a,i] = pq.top(); pq.pop();
        res+=a;
        if(a-B[i]>0) pq.push({a-B[i],i});
    }
    return res;
}

void sol(int tc) {
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=N;i++) cin >> B[i];
    ll ans=0;
    for(int l=1;l<=N;l++) for(int r=1;r<=N;r++) {
        ans = max(ans, f(l,r));
    }
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}