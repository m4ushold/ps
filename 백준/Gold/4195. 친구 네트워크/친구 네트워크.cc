#include <bits/stdc++.h>
using namespace std;

int P[202020], S[202020];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

void sol() {
    int n; cin >> n;
    init(200'000);
    map<string,int> id;
    int pv=0;
    for(int i=0;i<n;i++) {
        string a,b; cin >> a >> b;
        if(id[a]==0) id[a]=++pv;
        if(id[b]==0) id[b]=++pv;
        int s=id[a], e=id[b];
        Union(s,e);
        cout << S[Find(s)] << '\n';
    }
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}