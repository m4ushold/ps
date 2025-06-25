#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<19;

struct Seg {
    ll T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]=x;
        while(i>>=1) T[i]=max(T[i*2],T[i*2+1]);
    }
    ll qry(int l, int r) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret=max(ret,T[l++]);
            if(~r&1) ret=max(ret,T[r--]);
        }
        return ret;
    }
} modk, pmd;

int N, K, D, A[sz], DP[sz];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K >> D;
    int ans=0;
    for(int i=1;i<=N;i++) {
        cin >> A[i];
        DP[i] = max(modk.qry(A[i]%K, A[i]%K), pmd.qry(max(A[i]-D, 0), min(A[i]+D, sz-1))) + 1;
        ans = max(ans, DP[i]);
        modk.upd(A[i]%K, DP[i]), pmd.upd(A[i], DP[i]);
    }
    cout << ans;
    return 0;
}