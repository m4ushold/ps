#include <bits/stdc++.h>
using namespace std;

struct TwoSat {
    const static int MAX_V=101;
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
        vector<int> ret(CNT_V,-1);

        vector<pair<int,int>> v;
        for(int i=0;i<2*CNT_V;i++) v.push_back({ID[i],i});
        sort(v.begin(),v.end(), greater<>());

        for(auto [i,j]:v) if(ret[j/2]==-1) ret[j/2]=~j&1;
        return ret;
    }
} cnf;

int toV(string s) {
    int v = stoi(s.substr(0,s.size()-1))+1;
    return s.back()=='w' ? -v : v;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    while(cin >> n >> m && n) {
        cnf.clear();
        cnf.CNT_V = n;
        for(int i=0;i<m;i++) {
            string a,b; cin >> a >> b;
            cnf.addCNF(toV(a), toV(b));
        }
        cnf.addCNF(-1,-1);

        if(cnf.satisfy()) {
            vector<int> v=cnf.getVals();
            for(int i=1;i<cnf.CNT_V;i++) cout << i << (v[i] ? 'h' : 'w') << ' ';
            cout << "\n";
        } else cout << "bad luck\n";
    }
    return 0;
}