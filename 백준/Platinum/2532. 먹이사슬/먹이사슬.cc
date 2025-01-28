#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define comp(x) sort(all(x)), (x).erase(unique(all(x)), (x).end());
using namespace std;
using ll=long long;
using p=pair<ll,ll>;

constexpr int sz=1<<19;
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
    int n; cin >> n;
    vector<p> v(n);
    vector<int> a;
    for(auto &[l,r]:v) cin >> l >> l >> r, a.push_back(r);
    comp(a);
    comp(v);
    for(auto &[l,r]:v) r = lower_bound(all(a), r) - a.begin();
    sort(v.begin(),v.end(), [](p a, p b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
    reverse(v.begin(),v.end());
    for(auto [l,r]:v) seg.upd(r, seg.qry(0,r) + 1);
    cout << seg.T[1];
    return 0;
}