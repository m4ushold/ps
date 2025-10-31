#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

struct Seg {
    static const int sz=1<<19;
    vector<int> T[sz<<1];
    void bld() { 
        for(int i=sz-1;i>=1;i--) {
            T[i].resize(T[i*2].size()+T[i*2+1].size());
            merge(T[i*2].begin(),T[i*2].end(), T[i*2+1].begin(),T[i*2+1].end(), T[i].begin());
        }
    }
    vector<int>& operator[](int i) {return T[sz|i];}
    ll qry(int l, int r, int c) {
        ll ret=0,a=l,b=r;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret+=T[l].end() - lower_bound(all(T[l]),c), l++;
            if(~r&1) ret+=T[r].end() - lower_bound(all(T[r]),c), r--;
        }
        return ret;
    }
} seg;

void sol(int tc) {
    int n,m; cin >> n >> m;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        seg.T[i|seg.sz].push_back(v[i]);
    }
    seg.bld();

    for(int i=0;i<m;i++) {
        int a,p,f; cin >> a >> p >> f;
        if(v[a-1] >= p || a == n) cout << 0 << endl;
        else cout << seg.qry(a,min(n-1,a+f-1),p) << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}