#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Fenwick {
    const static int sz=1<<20;
    ll T[sz];
    ll sum(int i) {
        ll res=0;
        while(i) res+=T[i], i-=i&(-i);
        return res;
    }
    ll sum(int l, int r) {
        return sum(r)-(l?sum(l-1):0);
    }
    void add(int i, ll x) {
        while(i<sz) T[i]+=x, i+=i&(-i);
    }
    void add(int l, int r, ll x) {
        add(l, x), add(r+1, x);
    }
} fw;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k; cin >> n >> m >> k;
    for(ll i=1,a;i<=n;i++) cin >> a, fw.add(i, a);
    for(ll i=0,a,b,c;i<m+k;i++) {
        cin >> a >> b >> c;
        if(a==1) fw.add(b, c-fw.sum(b,b));
        else cout << fw.sum(b,c) << '\n';
    }
    return 0;
}