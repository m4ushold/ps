#include <bits/stdc++.h>
using namespace std;

int N, M, IN[202020], D[202020];
vector<int> G[202020];

int ord(char c) { return c=='K' ? 1 : (c=='D' ? 2 : 3); }
bool chk(string &s) {
    for(int i=1;i<=N;i++) if(s[i]=='K' && !D[i]) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> N >> M >> s;
    s="#"+s;
    for(int i=0,u,v;i<M;i++) {
        cin >> u >> v;
        if(ord(s[u]) > ord(s[v])) swap(u,v);
        if(s[u]=='K' && s[v]=='D') G[u].push_back(v), IN[v]++;
        else if(s[u]=='D' && s[v]=='H') G[u].push_back(v), IN[v]++;
        else if(s[u]=='K' && s[v]=='H') G[v].push_back(u), IN[u]++;
    }

    for(int t=0;t<3;t++) for(int i=1;i<=N;i++) if(!IN[i] && s[i]!='K') {
        for(int j:G[i]) --IN[j];
        G[i].clear();
    }

    queue<int> q;
    for(int i=1;i<=N;i++) if(!IN[i] && s[i]=='K') q.push(i), D[i]=1;
    while(q.size()) {
        int v=q.front(); q.pop();
        for(int i:G[v]) {
            D[i]=max(D[i],D[v]+1);
            if(--IN[i] == 0) q.push(i);
        }
    }
    int dap=(*max_element(D+1, D+N+1))/3*3;
    if(chk(s) || !dap) {cout << -1; return 0;}
    cout << dap;
    return 0;
}