#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    ll T[1<<18], sz=1<<17;
    void init() { for(int i=0;i<sz*2;i++) T[i]=0; }
    void update(int v, int x) {
        v|=sz, T[v]+=x;
        while(v>>=1) T[v]=T[v*2]+T[v*2+1];
    }
    ll query(int l, int r) {
        ll res=0;
        for(l|=sz,r|=sz ; l<=r ; l/=2,r/=2) {
            if(l&1) res+=T[l++];
            if(~r&1) res+=T[r--];
        }
        return res;
    }
} seg;

const int MOD=1e9+7;
ll N, A[101010], DP[12][101010];

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];

    seg.update(0,1);
    for(int i=1;i<=11;i++) {
        for(int j=1;j<=N;j++) seg.update(A[j], DP[i-1][j]), DP[i][j]=seg.query(0,A[j]-1)%MOD;
        seg.init();
    }
    ll res=0;
    for(int i=1;i<=N;i++) res=(res+DP[11][i])%MOD;
    cout << res;
    return 0;
}