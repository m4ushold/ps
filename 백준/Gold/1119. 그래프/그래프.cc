#include <bits/stdc++.h>
using namespace std;

int N, P[1<<17], S[1<<17];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    if(N==1) return cout << 0, 0;
    init(N);
    int a=0, b=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        char c; cin >> c;
        if(i>j) continue;
        if(c=='Y') a+=!Union(i,j);
    }
    for(int i=1;i<=N;i++) if(i==P[i]) {
        if(S[i]==1) return cout << -1, 0;
        b++;
    }
    if(b > a+1) cout << -1;
    else cout << b-1;
    return 0;
}