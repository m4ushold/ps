#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct TwoSat {
    const static int MAX_V=3030;
    vector<int> G[MAX_V*2];
    int IN[MAX_V*2], LOW[MAX_V*2], VI[MAX_V*2], ID[MAX_V*2], A[MAX_V];

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

    void addor(int a, int b) {
        a=idx(a), b=idx(b);
        G[n(a)].push_back(b), G[n(b)].push_back(a);
    }

    int n(int i) { return i&1?i-1:i+1; }
    int idx(int i) {return i<0?-(i+1)*2:i*2-1;}

    bool satisfy(int n) {
        tarjan(n);
        for(int i=0;i<n;i++) if(ID[i*2]==ID[i*2+1]) return 0;
        return 1;
    }

    vector<int> getVals(int n) {
        vector<int> ret(n,-1);

        vector<pair<int,int>> v;
        for(int i=0;i<2*n;i++) v.push_back({ID[i],i});
        sort(v.begin(),v.end(), greater<>());

        for(auto [i,j]:v) if(ret[j/2]==-1) ret[j/2]=~j&1;
        return ret;
    }
} cnf;

int N, M;
vector<int> FF[3030];
array<int,2> R[3030];
array<int,4> F[3030];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=0;j<4;j++) cin >> F[i][j];
    for(int i=1,a,b;i<=N;i++) {
        cin >> a >> b;
        R[i] = {a,b};
        FF[a].push_back(i);
        FF[b].push_back(-i);
    }
    for(int i=1;i<=N;i++) for(int j=i+1;j<=N;j++) {
        int a=R[i][0], b=R[i][1], c=R[j][0], d=R[j][1];
        if(a == c) cnf.addor(-i,-j);
        else if(a == d) cnf.addor(-i,j);
        else if(b == c) cnf.addor(i,-j);
        else if(b == d) cnf.addor(i,j);
    }
    for(int i=0,a,b,t;i<M;i++) {
        cin >> a >> b >> t;
        for(int u:FF[a]) for(int v:FF[b]) if(abs(u)!=abs(v)) {
            if(F[abs(u)][t-1] != F[abs(v)][t-1]) cnf.addor(-u,-v);
        }
    }
    if(cnf.satisfy(N)) {
        cout << "YES\n";
        auto v = cnf.getVals(N);
        vector<pair<int,int>> ans;
        for(int i=0;i<N;i++) {
            ans.push_back({R[i+1][v[i]^1],i+1});
        }
        sort(ans.begin(),ans.end());
        for(auto [i,j]:ans) cout << j <<' ';
    } else {
        cout << "NO\n";
    }
    return 0;
}