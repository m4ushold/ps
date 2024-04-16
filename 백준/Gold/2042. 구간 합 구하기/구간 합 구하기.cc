#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int SZ=1<<20;
ll N, M, K, A[SZ], T[SZ<<1];

void init()
{
    for(int i=1;i<=N;i++) T[i|SZ]=A[i];
    for(int i=SZ-1;i>=1;i--) T[i]=T[i*2]+T[i*2+1];
}

void update(int x, ll v)
{
    x|=SZ, T[x]=v;
    while(x>>=1) T[x]=T[x*2]+T[x*2+1];
}

ll query(int l, int r)
{
    ll ret=0;
    for(l|=SZ,r|=SZ;l<=r;l>>=1,r>>=1) {
        if(l&1) ret+=T[l++];
        if(~r&1) ret+=T[r--];
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++) cin >> A[i];
    init();
    for(ll i=0,a,b,c;i<M+K;i++) {
        cin >> a >> b >> c;
        if(a&1) update(b,c);
        else cout << query(b,c) << '\n';
    }
    return 0;
}