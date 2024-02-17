#include <bits/stdc++.h>
using namespace std;
using Point=pair<int,int>;

const int SZ=2020;
int N, M, K, C[SZ*2];
vector<int> G[SZ*2], R[SZ*2], V;
vector<vector<int>> S;

void dfs1(int v)
{
    C[v]=-1;
    for(auto i:G[v]) if(!C[i]) dfs1(i);
    V.push_back(v);
}

void dfs2(int v, int c)
{
    C[v]=c; S.back().push_back(v);
    for(auto i:R[v]) if(C[i]==-1) dfs2(i,c);
}

int getSCC()
{
    for(int i=0;i<2*SZ;i++) if(!C[i]) dfs1(i);
    reverse(V.begin(),V.end());
    int cnt=0;
    for(auto i:V) if(C[i]==-1) S.emplace_back(), dfs2(i,++cnt);
    return cnt;
}

int n(int i) { return i&1?i-1:i+1; }
int idx(int i) {return i<0?-(i+1)*2:i*2-1;}

void addEdge(int s, int e) {
    s=idx(s), e=idx(e);
    G[n(s)].push_back(e), G[n(e)].push_back(s);
    R[e].push_back(n(s)), R[s].push_back(n(e));
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        for(int i=0;i<2*SZ;i++) C[i]=0, G[i].clear(), R[i].clear();
        V.clear(), S.clear();

        cin >> N >> M >> K;
        for(int i=0,s,e;i<K;i++) {
            int a,b,c,d; cin >> a >> b >> c >> d;
            if(a==c&&b==d) continue;
            b+=1000, d+=1000;

            if(abs(a)>abs(c)) b=-b, d=-d;
            if(abs(b)>abs(d)) a=-a, c=-c;

            if(a==c) e=idx(a), G[n(e)].push_back(e), R[e].push_back(n(e));
            else if(b==d) e=idx(b), G[n(e)].push_back(e), R[e].push_back(n(e));
            else addEdge(a,b), addEdge(a,c), addEdge(d,b), addEdge(d,c);
        }
        
        getSCC();
        int f=1;
        for(int i=0;i<2000;i++) f&=(C[i*2]!=C[i*2+1]);
        cout << (f?"Yes\n":"No\n");
    }
    return 0;
}