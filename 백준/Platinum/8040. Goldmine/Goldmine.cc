#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<17;
struct LazySeg {
    ll T[sz<<1], L[sz<<1];
    void prop(int i, int s, int e) {
        if(!L[i]) return;
        T[i]+=L[i];
        if(s!=e) L[i*2]+=L[i], L[i*2+1]+=L[i];
        L[i]=0;
    }
    void upd(int l, int r, ll v, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {L[i]+=v, prop(i,s,e); return;}
        int m=s+e>>1;
        upd(l,r,v,i*2,s,m), upd(l,r,v,i*2+1,m+1,e);
        T[i]=max(T[i*2],T[i*2+1]);
    }
    ll qry(int l, int r, int i=1, int s=0, int e=sz-1) {
        prop(i,s,e);
        if(r<s || e<l) return 0;
        else if(l<=s && e<=r) return T[i];
        int m=s+e>>1;
        return max(qry(l,r,i*2,s,m),qry(l,r,i*2+1,m+1,e));
    }
} seg;

int S,W,N;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> S >> W >> N;
    vector<pair<int,int>> v(N);
    queue<pair<int,int>> q;

    for(auto &[x,y]:v) cin >> x >> y, x+=30'000, y+=30'000;
    sort(v.begin(),v.end());
    int mx=0;
    for(auto [x,y]:v) {
        while(q.size() && x-q.front().first > S) {
            auto [xx,yy] = q.front(); q.pop();
            seg.upd(yy, yy+W, -1);
        }
        seg.upd(y, y+W, 1);
        q.push({x,y});
        mx = max<int>(mx, seg.qry(0,sz-1));
    }
    cout << mx;
    return 0;
}