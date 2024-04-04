#include <bits/stdc++.h>
using namespace std;

const int MAX_V=10101;
vector<int> G[MAX_V]; 
int IN[MAX_V], LOW[MAX_V], VI[MAX_V], ID[MAX_V];
vector<vector<int>> SCC;

void tarjan(int n){
    int c=0;
    stack<int> s;
    function<void(int)> dfs=[&](int v) {
        IN[v]=LOW[v]=++c, VI[v]=1, s.push(v);
        for(auto i : G[v]) {
            if(!IN[i]) dfs(i), LOW[v]=min(LOW[v], LOW[i]); 
            else if(VI[i]) LOW[v]=min(LOW[v], IN[i]);
        }
        
        if(LOW[v]==IN[v]) {
            SCC.emplace_back();
            while(!s.empty()) {
                int t=s.top(); s.pop(), SCC.back().push_back(t), ID[t]=SCC.size(), VI[t]=0;
                if(v==t) break;
            }
        }
    };
    for(int i=1; i<=n; i++) if(!IN[i]) dfs(i);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int v,e; cin >> v >> e;
    for(int i=0,a,b;i<e;i++) cin >> a >> b, G[a].push_back(b);
    tarjan(v);

    for(auto& a:SCC) sort(a.begin(),a.end());
    sort(SCC.begin(),SCC.end());
    cout << SCC.size() << '\n';
    for(auto a:SCC) {
        for(int i:a) cout << i << " ";
        cout << "-1\n";
    }

    return 0;
}