#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

const int sz=1<<19;

vector<int> yv;

struct LazySeg {
    ll T[sz<<1], L[sz<<1];
    void update(int l, int r, int v, int i=1, int s=0, int e=sz-1) {
        if(r<s || e<l) return;
        else if(l<=s && e<=r) L[i]+=v;
        else {
            int m=s+e>>1;
            update(l,r,v,i*2,s,m), update(l,r,v,i*2+1,m+1,e);
        }
        if(L[i]) T[i]=yv[e+1]-yv[s];
        else if(s==e) T[i]=0;
        else T[i]=T[i*2]+T[i*2+1];
    }
} seg;

void sol(int tc) {
    int n; cin >> n;
    vector<array<int,4>> v;
    for(int i=0;i<n;i++) {
        int x1,x2,y1,y2; cin >> x1 >> x2 >> y1 >> y2;
        v.push_back({x1,y1,y2,1});
        v.push_back({x2,y1,y2,-1});
        yv.push_back(y1), yv.push_back(y2);
    }
    prs(yv);
    sort(all(v));

    ll ans=0;
    for(int i=0;i<v.size();i++) {
        auto [x,s,e,f] = v[i];
        if(i) {
            ans += (x-v[i-1][0]) * seg.T[1];
        }
        s=lower_bound(all(yv),s)-yv.begin();
        e=lower_bound(all(yv),e)-yv.begin();
        seg.update(s,e-1,f);
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