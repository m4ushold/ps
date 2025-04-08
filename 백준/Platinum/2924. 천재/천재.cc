#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int P[1<<19], S[1<<19];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,a,b,c,d; cin >> n >> a >> b >> c >> d;
    init(n);
    for(int i=1,x;i<=n;i++) cin >> x, Union(i, x);
    ll l=1;
    for(int i=1+c;i<=n-d;i++) l=lcm(l,S[Find(i)]);
    a--, b--;
    if(!a) cout << b/l+1;
    else cout << b/l - (a-1)/l;
    return 0;
}