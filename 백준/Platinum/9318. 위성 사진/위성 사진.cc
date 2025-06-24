#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<20;

struct {
    int T[sz<<1], L[sz<<1];
    void update(int l, int r, int v, int i=1, int s=0, int e=sz-1) {
        if(r<s || e<l) return;
        else if(l<=s && e<=r) L[i]+=v;
        else {
            int m=s+e>>1;
            update(l,r,v,i*2,s,m), update(l,r,v,i*2+1,m+1,e);
        }
        if(L[i]) T[i]=e-s+1;
        else if(s==e) T[i]=0;
        else T[i]=T[i*2]+T[i*2+1];
    }
} seg;

vector<tuple<int,int,int>> X[sz];

void sol() {
    for(int i=0;i<sz;i++) X[i].clear();
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        y2--;
        X[x1].push_back({y1,y2,1});
        X[x2].push_back({y1,y2,-1});
    }
    ll dap=0;
    for(int i=0;i<sz;i++) {
        for(auto [l,r,a]:X[i]) seg.update(l,r,a);
        dap+=seg.T[1];
    }
    cout << dap << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}