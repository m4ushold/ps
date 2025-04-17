#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz=1<<17;
int D[sz];
struct LazySeg {
    ll T[sz<<1];
    pair<ll,ll> L[sz<<1];
    LazySeg() {for(int i=0;i<sz*2;i++) T[i]=1e9, L[i]={1e9,1e9};}
    void prop(int i, int s, int e) {
        if(L[i].second==1e9) return;
        if(L[i].first < T[i]) {
            T[i] = L[i].first;
            if(s==e) D[s] = L[i].second;
        }
        if(s!=e) {
            for(auto j:{i*2,i*2+1}) {
                if(L[j].first > L[i].first) L[j] = L[i];
            }
        }
        L[i]={1e9,1e9};
    }
    void upd(int l, int r, ll v, int idx, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[i]={v,idx}, prop(i,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,idx,i*2,s,m), upd(l,r,v,idx,i*2+1,m+1,e);
        T[i]=min(T[i*2],T[i*2+1]);
    }
    ll qry(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return 1e9;
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        return min(qry(l,r,i*2,s,m),qry(l,r,i*2+1,m+1,e));
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=1,x;i<=n;i++) cin >> x, seg.upd(i, i, x, 0);

    int q; cin >> q;
    for(int i=1,l,r,x;i<=q;i++) {
        cin >> l >> r >> x;
        seg.upd(l, r, x, i);
    }
    map<int,int> m;
    for(int i=1;i<=n;i++) {
        cout << seg.qry(i,i) << ' ';
        m[D[i]]++;
    }
    cout << '\n';

    vector<int> res;
    int s=0;
    for(int i=q+1;i>1;i--) s+=m[i], res.push_back(n-s);
    reverse(res.begin(),res.end());
    for(int i:res) cout << i << ' ';
    cout << '\n';
    return 0;
}