#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, M, P[303030], S[303030];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

void sol(int tc) {
    cin >> N >> M;
    init(N*3);
    int cnt=0;
    for(int i=1;i<=M;i++) {
        int op,x,y; cin >> op >> x >> y;
        --x, --y;
        if(min(x,y)<0 || N-1<max(x,y)) {cnt++; continue;}
        else if(op==1) {
            if(Find(x*3)==Find(y*3+1) || Find(x*3)==Find(y*3+2)) {cnt++;continue;}
            else for(int j=0;j<3;j++) Union(x*3+j,y*3+j);
        } else {
            if(Find(x*3)==Find(y*3) || Find(x*3)==Find(y*3+2)) {cnt++;continue;}
            else for(int j=0;j<3;j++) Union(x*3+j,y*3+(j+1)%3);
        }
    }
    cout << cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}