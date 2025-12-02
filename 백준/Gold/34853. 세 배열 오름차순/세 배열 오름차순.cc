#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
 
ll N, Q;
vector<int> A[101010];
 
pll f(int a, int b, int c, int x) {
    ll s=0,e=0;
    s = lower_bound(all(A[a]),x)-A[a].begin() + lower_bound(all(A[b]),x)-A[b].begin() + lower_bound(all(A[c]),x)-A[c].begin();
    e = upper_bound(all(A[a]),x)-A[a].begin() + upper_bound(all(A[b]),x)-A[b].begin() + upper_bound(all(A[c]),x)-A[c].begin();
    return {s+1,e};
}
 
void sol(int tc) {
    cin >> N >> Q;
    for(int i=1;i<=N;i++) {
        int k; cin >> k;
        A[i].resize(k);
        for(int &j:A[i]) cin >> j;
        sort(all(A[i]));
    }
 
    auto [s,e] = f(1,2,3,1);
 
    for(int i=1,a,b,c,j;i<=Q;i++) {
        cin >> a >> b >> c >> j;
        int l=1, r=1e9;
        while(l<r) {
            int m=l+r+1>>1;
            auto [s,e] = f(a,b,c,m);
            if(s<=j) l=m;
            else r=m-1;
        }
        auto [s,e]=f(a,b,c,l);
        if(s>j || j>e) l=r;
 
        cout << l << endl;
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}