#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll MAX_V=101;
ll N, M, A[MAX_V], B[MAX_V], vi[MAX_V];
vector<ll> G[MAX_V];

bool dfs(ll v)  {
    vi[v]=1;
    for(ll i:G[v]) {
        if(B[i]==-1 || !vi[B[i]] && dfs(B[i])) {
            A[v]=i, B[i]=v;
            return 1;
        }
    }
    return 0;
}

ll matching() {
    ll cnt=0;
    for(ll i=0;i<MAX_V;i++) A[i]=B[i]=-1;
    for(ll i=0;i<MAX_V;i++) {
        for(ll i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

bool chk(vector<pair<ll,ll>> &a, vector<pair<ll,ll>> &b, ll m) {
    for(ll i=0;i<N;i++) G[i].clear();
    for(ll i=0;i<N;i++) for(ll j=0;j<N;j++) if(abs(a[i].first-b[j].first)+abs(a[i].second-b[j].second) <= m) {
        G[i].push_back(j);
    }
    return matching() == N;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<pair<ll,ll>> a(N),b(N);
    for(auto &[x,y]:a) cin >> x >> y;
    for(auto &[x,y]:b) cin >> x >> y;
    ll l=0,r=1e9;
    while(l<r) {
        ll m=l+r>>1;
        if(chk(a,b,m)) r=m;
        else l=m+1;
    }
    cout << r;
    return 0;
}