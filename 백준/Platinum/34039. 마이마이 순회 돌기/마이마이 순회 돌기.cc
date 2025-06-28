#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<17;

struct Seg {
    ll T[sz<<1], S[sz<<1];
    void upd(int i, int x) {
        T[i|sz]+=x;
        S[i|sz]+=i*x;
        i|=sz;
        while(i>>=1) T[i]=T[i*2]+T[i*2+1], S[i]=S[i*2]+S[i*2+1];
    }
    ll sum(int l, int r) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret+=S[l++];
            if(~r&1) ret+=S[r--];
        }
        return ret;
    }
    ll qry(int l, int r) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret+=T[l++];
            if(~r&1) ret+=T[r--];
        }
        return ret;
    }
    ll qry(int t) {
        int l=0, r=sz-1;
        while(l<r) {
            int m=l+r+1>>1;
            if(sum(0, m) <= t) l=m;
            else r=m-1;;
        }
        
        t-=sum(0,l);
        ll res=qry(0,l);
        if(l<sz && sum(l+1,l+1)) {
            res += t/(l+1);
        }
        return res;
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,q; cin >> n >> q;
    vector<int> time(n);
    for(int &i:time) cin >> i, seg.upd(i, 1);
    time.insert(time.begin(), 0);
    for(int i=0,op,v,t,j;i<q;i++) {
        cin >> op;
        if(op==1) cin >> j >> v, seg.upd(time[j], -1), seg.upd(v, 1), time[j]=v;
        else if(op==2) {
            cin >> t;
            cout << seg.qry(t) << '\n';
        }
        else cin >> v, time.push_back(v), seg.upd(v, 1);
    }
    return 0;
}