#include <bits/stdc++.h>
using namespace std;

struct TwoSat {
    const static int MAX_V=10101;
    vector<int> G[MAX_V*2];
    int CNT_V, IN[MAX_V*2], LOW[MAX_V*2], VI[MAX_V*2], ID[MAX_V*2];

    void clear() {
        memset(IN, 0, sizeof IN), memset(LOW, 0, sizeof LOW), memset(VI, 0, sizeof VI), memset(ID, 0, sizeof ID);
        for(int i=0;i<MAX_V*2;i++) G[i].clear();
    }

    void tarjan() {
        int c=0, scc=0;
        stack<int> s;
        function<void(int)> dfs=[&](int v) {
            IN[v]=LOW[v]=++c, VI[v]=1, s.push(v);
            for(auto i : G[v]) {
                if(!IN[i]) dfs(i), LOW[v]=min(LOW[v], LOW[i]); 
                else if(VI[i]) LOW[v]=min(LOW[v], IN[i]);
            }
            
            if(LOW[v]==IN[v]) {
                scc++;
                while(!s.empty()) {
                    int t=s.top(); s.pop(), ID[t]=scc, VI[t]=0;
                    if(v==t) break;
                }
            }
        };
        for(int i=0; i<2*CNT_V; i++) if(!IN[i]) dfs(i);
    }

    void addCNF(int a, int b) {
        a=idx(a), b=idx(b);
        G[n(a)].push_back(b), G[n(b)].push_back(a);
    }

    int n(int i) { return i&1?i-1:i+1; }
    int idx(int i) {return i<0?-(i+1)*2:i*2-1;}

    bool satisfy() {
        tarjan();
        for(int i=0;i<CNT_V;i++) if(ID[i*2]==ID[i*2+1]) return 0;
        return 1;
    }

    vector<int> getVals() { // shuold call satisfy before
        vector<int> ret(CNT_V+1,-1);

        vector<pair<int,int>> v;
        for(int i=0;i<2*CNT_V;i++) v.push_back({ID[i],i});
        sort(v.begin(),v.end(), greater<>());

        for(auto [i,j]:v) if(ret[j/2]==-1) ret[j/2]=~j&1;
        return ret;
    }
} G;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    G.CNT_V=2000;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
        char c; cin >> c;
        if(c=='#') G.addCNF(-i,1000+j), G.addCNF(i, -1000-j);
        else if(c=='*') G.addCNF(i,1000+j), G.addCNF(-i, -1000-j);
    }
    
    cout << G.satisfy();
    return 0;
}