#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1<<20;
int N, Q, P[sz], S[sz];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    init(2*N+2);
    int ans=0;
    for(int i=0,a,b;i<Q;i++) {
        cin >> a >> b;
        int aa=0,bb=0;
        if(Find(a*2) == Find(a*2+1)) aa+=S[Find(a*2)]/2;
        if(Find(a*2) != Find(b*2) && Find(b*2) == Find(b*2+1)) aa+=S[Find(b*2)]/2;

        Union(a*2, b*2+1), Union(a*2+1, b*2);
        if(Find(a*2) == Find(a*2 + 1)) bb=S[Find(a*2)]/2;
        ans += bb-aa;
        cout << ans << '\n';
    }
    return 0;
}