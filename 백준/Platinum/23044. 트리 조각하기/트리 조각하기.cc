#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, C[202020], D[202020], DD[202020];
vector<int> G[202020];

int chk(int p) {
    for(int i=1;i<=N;i++) DD[i]=0;
    queue<int> q;
    for(int i=1;i<=N;i++) if(D[i] > p) q.push(i), DD[i]=1;
    while(q.size()) {
        int v=q.front(); q.pop();
        for(int i:G[v]) if(!DD[i]) DD[i]=DD[v]+1, q.push(i);
    }

    for(int i=1;i<=N;i++) {
        if(DD[i] > p && C[i]) return 0;
        if(DD[i] <= p && !C[i]) return 0;
    }
    return 1;
}

void sol(int tc) {
    cin >> N;
    for(int i=1;i<=N;i++) cin >> C[i];
    for(int i=1;i<N;i++) {
        int a,b; cin >> a >> b;
        G[a].push_back(b), G[b].push_back(a);
    }
    queue<int> q;
    for(int i=1;i<=N;i++) if(!C[i]) q.push(i), D[i]=1;
    while(q.size()) {
        int v=q.front(); q.pop();
        for(int i:G[v]) if(!D[i]) D[i]=D[v]+1, q.push(i);
    }
    
    int l=1, r=N+1;
    while(l<r) {
        int m=l+r+1>>1;
        if(chk(m)) l=m;
        else r=m-1;
    }
    cout << l << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}