#include <bits/stdc++.h>
using namespace std;
using Point=pair<int,int>;

const int MAX_V=505050;
vector<int> G[MAX_V*2];
int N, M, C, K, IN[MAX_V*2], LOW[MAX_V*2], VI[MAX_V*2], ID[MAX_V*2], A[MAX_V];

int n(int i) { return i&1?i-1:i+1; }
int idx(int i) {return i<0?-(i+1)*2:i*2-1;}

void tarjan(int n) {
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
    for(int i=0; i<2*n; i++) if(!IN[i]) dfs(i);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> C >> K;
    for(int i=1,a;i<=M;i++) cin >> a, A[a]=1;
    for(int i=0,u,v;i<C;i++) {
        cin >> u >> v;
        A[u]=A[v]=0, u=idx(u), v=idx(v);
        G[n(u)].push_back(v), G[n(v)].push_back(u);
    }
    for(int i=0,u,v;i<K;i++) {
        cin >> u >> v;
        u=idx(-u), v=idx(-v);
        G[n(u)].push_back(v), G[n(v)].push_back(u);
    }
    for(int i=1,u,v;i<=N;i++) if(A[i]) {
        u=idx(i), v=idx(i);
        G[n(u)].push_back(v), G[n(v)].push_back(u);
    }
    tarjan(N);

    int f=1;
    for(int i=1;i<=N;i++) f&=(ID[idx(i)]!=ID[idx(-i)]);
    cout << (f ? "YES" : "NO");
    return 0;
}