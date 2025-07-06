#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1<<17;
int P[sz], S[sz], L[sz], R[sz], A[sz];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,a,b; cin >> n >> a >> b;
    init(n);
    for(int i=0;i<n;i++) {
        cin >> L[i] >> R[i] >> A[i];
    }
    queue<array<int,3>> q;
    if(A[a]^A[b]) return cout << 0, 0;
    Union(a,b);
    q.push({0,a,b});
    while(q.size()) {
        auto [c,a,b] = q.front(); q.pop();
        if(A[a]^A[b]) return cout << c, 0;

        if(Union(L[a], L[b])) q.push({c+1, L[a], L[b]});
        if(Union(R[a], R[b])) q.push({c+1, R[a], R[b]});
    }
    cout << "indistinguishable";
    return 0;
}