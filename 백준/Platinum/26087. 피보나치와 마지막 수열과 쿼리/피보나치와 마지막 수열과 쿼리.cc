#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

constexpr int mod = 1e9+7;

int P[1010101], A[1010101], F[1010101]={1,1};
void init(int n) { for(int i=1;i<=n;i++) P[i]=i; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (P[u]=v, true); }

void sol(int tc) {
    int n,q; cin >> n >> q;
    for(int i=2;i<=n;i++) F[i]=(F[i-1]+F[i-2])%mod;
    init(n);
    vector<pll> v(q);
    for(auto &[l,r]:v) cin >> l >> r;
    reverse(all(v));
    for(auto [l,r]:v) {
        int i=l;
        while(i<=r) {
            Union(l,i);
            if(A[i]) i=Find(i)+1;
            else A[i]=F[i-l+1], i++;
        }
    }
    for(int i=1;i<=n;i++) cout << A[i] << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}