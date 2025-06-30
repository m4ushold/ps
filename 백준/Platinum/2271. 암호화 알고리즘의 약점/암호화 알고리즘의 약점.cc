#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<13;

struct {
    ll T[sz<<1];
    void clear() {
        memset(T, 0, sizeof(T));
    }
    void upd(int i, int x) {
        T[i|=sz]=x;
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

bool sol(vector<int> v) {
    seg.clear();
    int n = v.size();
    for(int i=0;i<n;i++) {
        int mx = v[i+1];
        for(int j=i+2;j<n;j++) {
            if(v[i] < v[j] && v[j] < mx) {
                if(seg.qry(v[j]+1, mx-1)) return 1;
            }
            mx = max(mx, v[j]);
        }
        seg.upd(v[i], 1);
    }
    return 0;
}

void sol() {
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    int ans = sol(v);
    reverse(v.begin(),v.end());
    ans |= sol(v);
    cout << (ans ? "Yes" : "No") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    
    return 0;
}