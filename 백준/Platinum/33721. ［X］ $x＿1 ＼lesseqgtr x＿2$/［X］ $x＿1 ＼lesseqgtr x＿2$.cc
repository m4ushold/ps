#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1<<19;
int N, M, C[sz], IN[sz], D[sz], A[sz];
vector<int> G[sz], R[sz], V, GG[sz];
vector<vector<int>> S;

void dfs1(int v) {
    C[v]=-1;
    for(auto i:G[v]) if(!C[i]) dfs1(i);
    V.push_back(v);
}

void dfs2(int v, int c) {
    C[v]=c; S.back().push_back(v);
    for(auto i:R[v]) if(C[i]==-1) dfs2(i,c);
}

int getSCC() {
    for(int i=1;i<=N;i++) if(!C[i]) dfs1(i);
    reverse(V.begin(),V.end());
    int cnt=0;
    for(auto i:V) if(C[i]==-1) S.emplace_back(), dfs2(i,++cnt);
    return cnt;
}

void sol(int tc) {
    cin >> N >> M;
    vector<pll> v, d;
    for(int i=0;i<M;i++) {
        string c;
        int a,b;
        cin >> a >> c >> b;
        if(c == "<") {
            v.push_back({a,b});
            G[a].push_back(b);
            R[b].push_back(a);
        } else if(c == ">") {
            v.push_back({a,b});
            G[b].push_back(a);
            R[a].push_back(b);
        } else if(c == ">=") {
            G[b].push_back(a);
            R[a].push_back(b);
        } else if(c == "<=") {
            G[a].push_back(b);
            R[b].push_back(a);
        } else if(c == "==") {
            G[a].push_back(b), G[b].push_back(a);
            R[b].push_back(a), R[a].push_back(b);
        } else {
            v.push_back({a,b});
            d.push_back({a,b});
        }
    }

    int scc_sz = getSCC();
    for(auto [a,b]:v) if(C[a] == C[b]) {
        cout << "NO";
        return;
    }
    for(int i=1;i<=N;i++) {
        for(int j:G[i]) if(C[i]!=C[j]) GG[C[i]].push_back(C[j]);
    }
    for(int i=1;i<=scc_sz;i++) {
        prs(GG[i]);
        for(int j:GG[i]) IN[j]++;
    }

    queue<int> q;
    for(int i=1;i<=scc_sz;i++) if(IN[i] == 0) q.push(i);
    int pv=0;
    while(q.size()) {
        int v = q.front(); q.pop();
        A[v] = ++pv;
        for(int i:GG[v]) if(--IN[i] == 0) q.push(i);
    }
    memset(IN, 0, sizeof(IN));
    for(auto [a,b]:d) {
        if(A[C[a]] > A[C[b]]) GG[C[b]].push_back(C[a]);
        else GG[C[a]].push_back(C[b]);
    }
    for(int i=1;i<=scc_sz;i++) {
        prs(GG[i]);
        for(int j:GG[i]) IN[j]++;
    }

    for(int i=1;i<=N;i++) if(IN[i]==0) q.push(i), D[i]=1;
    while(q.size()) {
        int v = q.front(); q.pop();
        for(int i:GG[v]) {
            if(--IN[i] == 0) q.push(i);
            D[i] = max(D[i], D[v]+1);
        }
    }
    cout << "YES" << endl;
    for(int i=1;i<=N;i++) cout << D[C[i]] << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}