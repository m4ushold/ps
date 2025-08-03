#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<17;
struct {
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
} eka;

int S[sz];

void sol(int tc) {
    int n; cin >> n;
    vector<array<int,3>> qry(n);
    vector<int> ans(n);
    for(int i=0;i<n;i++) {
        cin >> qry[i][0] >> qry[i][1], qry[i][2]=i;
    }

    for(int i=2;i<sz;i++) if(S[i]==0) for(int j=i;j<sz;j+=i) S[j]=i;
    sort(qry.begin(),qry.end());
    int idx=1;
    for(auto [n,k,i]:qry) {
        while(idx<n) {
            ++idx;
            eka.upd(S[idx],1);
        }
        ans[i] = eka.qry(0,k);
    }
    for(int i:ans) cout << i << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}