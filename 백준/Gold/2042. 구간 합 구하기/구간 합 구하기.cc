#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<20;
struct {
    ll T[sz];
    void add(int i, ll x) {for(;i<sz;i+=i&-i) T[i]+=x;}
    ll sum(int i) {
        ll res=0;
        for(;i;i-=i&-i) res+=T[i];
        return res;
    }
    ll sum(int l, int r) {
        return sum(r)-sum(l-1);
    }
} fw;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k; cin >> n >> m >> k;
    for(ll i=1,x;i<=n;i++) cin >> x, fw.add(i,x);
    for(ll i=1,a,b,c;i<=m+k;i++) {
        cin >> a >> b >> c;
        if(a == 1) fw.add(b, c-fw.sum(b,b));
        else cout << fw.sum(b,c) << '\n';
    }
    return 0;
}