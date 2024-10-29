#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Fenwick2D {
    static const int sz=5050;
    ll T[sz][sz];
    void add(int i, int j, ll x) {
        for(++i;i<sz;i+=i&-i) for(int k=j+1;k<sz;k+=k&-k) T[i][k]+=x;
    }
    ll sum(int i, int j) {
        ll res=0;
        for(++i;i;i-=i&-i) for(int k=j+1;k;k-=k&-k) res+=T[i][k];
        return res;
    }
} fw;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    for(int i=1,op,l,r,ll,rr,x,y,d;i<=q;i++) {
        cin >> op;
        if(op==1) {
            cin >> l >> r >> ll >> rr >> d;
            fw.add(l,r,d), fw.add(ll+1,rr+1,d);
            fw.add(ll+1,r,-d), fw.add(l,rr+1,-d);
        } else {
            cin >> x >> y;
            cout << fw.sum(x,y) << '\n';
        }
    }
    return 0;
}