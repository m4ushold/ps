#include <bits/stdc++.h>
using namespace std;

constexpr int sz=1<<20;
struct {
    pair<int,int> T[sz<<1];
    void upd(int i, int x, int j) {
        T[i|=sz]={x,j};
        while(i/=2) T[i]=max(T[i*2],T[i*2+1]);
    }
    pair<int,int> qry(int l, int r) {
        pair<int,int> res={0,0};
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) res=max(res,T[l++]);
            if(~r&1) res=max(res,T[r--]);
        }
        return res;
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    vector<int> p(n+1);
    for(auto &[a,b]:v) cin >> a >> b;
    sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b){
        if(a.first==b.first) return a.second > b.second;
        return a.first < b.first;
    });
    reverse(v.begin(),v.end());

    for(int i=1;i<=n;i++) {
        auto [a,b]=v[i-1];
        auto [c,d]=seg.qry(0, b);
        p[i]=d;
        seg.upd(b, c+1, i);
    }

    cout << seg.T[1].first << '\n';
    vector<int> dap;
    dap.push_back(seg.T[1].second);
    while(p[dap.back()]) dap.push_back(p[dap.back()]);
    for(auto i:dap) cout << v[i-1].first << " " << v[i-1].second << '\n';
    return 0;
}