#include <bits/stdc++.h>
using namespace std;

struct LazySeg {
    const static int sz=1<<18;
    int T[sz<<1], L[sz<<1];
    void prop(int i, int s, int e) {
        if(L[i]==0) return;
        T[i]=max(T[i], L[i]);
        if(s!=e) L[i*2]=max(L[i*2], L[i]), L[i*2+1]=max(L[i*2+1], L[i]);
        L[i]=0;
    }
    void upd(int l, int r, int x, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[i]=x, prop(i,s,e); return;}
        int m=s+e>>1;
        upd(l,r,x,i*2,s,m), upd(l,r,x,i*2+1,m+1,e);
        T[i]=max(T[i*2],T[i*2+1]);
    }
    int qry(int l=0, int r=sz-1, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return 0;
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        return max(qry(l,r,i*2,s,m),qry(l,r,i*2+1,m+1,e));
    }
} seg;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(auto &[i,j]:v) cin >> i >> j, swap(i,j), j+=i-1;
    vector<int> a;
    for(auto [i,j]:v) a.push_back(i), a.push_back(j);

    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()), a.end());

    for(auto &[i,j]:v) {
        i = lower_bound(a.begin(),a.end(),i)-a.begin()+1;
        j = lower_bound(a.begin(),a.end(),j)-a.begin()+1;
    }

    for(auto [i,j]:v) {
        int mx=seg.qry(i,j);
        seg.upd(i,j,mx+1);
    }

    cout << seg.qry();
    return 0;
}