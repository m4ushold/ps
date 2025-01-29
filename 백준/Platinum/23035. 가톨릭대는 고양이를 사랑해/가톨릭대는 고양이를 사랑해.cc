#include <bits/stdc++.h>
using namespace std;

constexpr int sz=1<<17;
struct {
    int T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]=x;
        while(i/=2) T[i]=max(T[i*2],T[i*2+1]);
    }
    int qry(int l, int r) {
        int res=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) res=max(res,T[l++]);
            if(~r&1) res=max(res,T[r--]);
        }
        return res;
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,t; cin >> n >> m >> t;
    vector<pair<int,int>> v;
    vector<int> a;
    for(int i=0,x,y;i<t;i++) {
        cin >> x >> y;
        if(x<=n && y<=m) v.push_back({x,y}), a.push_back(y);
    }
    sort(a.begin(),a.end()), a.erase(unique(a.begin(),a.end()),a.end());
    for(auto &[x,y]:v) y=lower_bound(a.begin(),a.end(),y)-a.begin();
    sort(v.begin(),v.end());
    for(auto [x,y]:v) seg.upd(y, seg.qry(0,y)+1);
    cout << seg.T[1];
    return 0;
}