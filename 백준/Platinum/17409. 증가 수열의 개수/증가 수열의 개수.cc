#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9+7;
ll N, K, D[11][101010], A[101010];

struct Seg {
    static const int sz=1<<17;
    ll T[sz<<1];
    ll f(ll a, ll b){return (a+b)%MOD;}
    void clear() {memset(T, 0,sizeof(T));}
    void bld() { for(int i=sz-1;i>=1;i--) T[i]=f(T[i*2],T[i*2+1]); }
    void upd(int i, int x) {
        T[i|=sz]=x;
        while(i>>=1) T[i]=f(T[i*2],T[i*2+1]);
    }
    ll& operator[](int i) {return T[sz|i];}
    ll qry(int l, int r) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret=f(ret,T[l++]);
            if(~r&1) ret=f(ret,T[r--]);
        }
        return ret;
    }
} seg;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1;i<=N;i++) cin >> A[i];
    seg.upd(0,1);
    for(int i=1;i<=K;i++) {
        for(int j=1;j<=N;j++) {
            seg.upd(A[j], D[i-1][j]);
            D[i][j]=seg.qry(0,A[j]-1);
        }
        seg.clear();
    }
    ll dap=0;
    for(int i=1;i<=N;i++) dap=(dap+D[K][i])%MOD;
    cout << dap;
    return 0;
}