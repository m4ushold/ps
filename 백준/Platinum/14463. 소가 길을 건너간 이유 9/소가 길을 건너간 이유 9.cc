#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz=1<<17;
struct {
    int T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]+=x;
        while(i>>=1) T[i]=T[i<<1]+T[i<<1|1];
    }
    int qry(int l, int r) {
        int res=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) res+=T[l++];
            if(~r&1) res+=T[r--];
        }
        return res;
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=1,a;i<=n*2;i++) {
        cin >> a;
        a--;
        if(v[a].first) v[a].second=i;
        else v[a].first=i;
    }
    sort(v.begin(),v.end());
    ll dap=0;
    for(auto [s,e]:v) {
        dap+=seg.qry(s,e);
        seg.upd(e,1);
    }
    cout << dap;
    return 0;
}