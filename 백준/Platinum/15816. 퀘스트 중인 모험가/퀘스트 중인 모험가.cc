#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<21;
struct Seg {
    ll T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]+=x;
        while(i>>=1) T[i]=T[i*2]+T[i*2+1];
    }
    ll qry(int l, int r) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret+=T[l++];
            if(~r&1) ret+=T[r--];
        }
        return ret;
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n), t;
    for(int &i:v) cin >> i, t.push_back(i);
    int m; cin >> m;
    vector<array<int,3>> q(m);
    for(auto &[a,b,c]:q) {
        cin >> a >> b;
        if(a==1) t.push_back(b);
        if(a==2) cin >> c;
    }
    sort(t.begin(),t.end());
    t.erase(unique(t.begin(),t.end()),t.end());

    for(int i:v) seg.upd(lower_bound(t.begin(),t.end(),i)-t.begin(), 1);
    for(auto [a,b,c]:q) {
        if(a == 1) {
            seg.upd(lower_bound(t.begin(),t.end(),b)-t.begin(),1);
        } else {
            cout << c-b+1-seg.qry(upper_bound(t.begin(),t.end(),b-1)-t.begin(), upper_bound(t.begin(),t.end(),c)-t.begin()-1) << '\n';
        }
    }
    return 0;
}