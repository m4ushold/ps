#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<tuple<ll,ll,ll>> G[11];
pair<ll,ll> A[11];

void dfs(ll v=0, ll b=-1) {
    ll g=gcd(A[v].first, A[v].second);
    A[v].first/=g, A[v].second/=g;
    for(auto [i,p,q]:G[v]) if(i!=b) {
        A[i] = {A[v].first*q, A[v].second*p};
        dfs(i,v);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    for(ll i=1,a,b,p,q;i<n;i++) {
        cin >> a >> b >> p >> q;
        G[a].emplace_back(b,p,q), G[b].emplace_back(a,q,p);
    }
    for(int i=0;i<n;i++) A[i]={1,1};
    dfs();

    ll l=1,g=0;
    for(ll i=0;i<n;i++) l=lcm(l, A[i].second);
    for(ll i=0;i<n;i++) A[i].first*=l, A[i].first/=A[i].second, g=gcd(g, A[i].first);
    for(ll i=0;i<n;i++) cout << A[i].first/g << ' ';

    return 0;
}