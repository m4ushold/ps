#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, M, A[202020], V[202020], D[202020], U[202020];
vector<int> G[202020];

int dfs(int v, int p=-1) {
    V[v]=1;
    D[v]=1;
    int res=0;
    for(int i:G[v]) {
        if(i!=p) {
            if(V[i]) return -1;
            res |= dfs(i,v);
            D[v] += D[i];
        }
    }
    return res;
}

void sol(int tc) {
    cin >> N >> M;
    int cnt=0;
    vector<int> rt;
    for(int i=1;i<=N;i++) {
        cin >> A[i], cnt+=A[i];
        if(!A[i]) rt.push_back(i);
    }

    for(int i=1;i<=M;i++) {
        int a,b; cin >> a >> b;
        G[a].push_back(b), G[b].push_back(a);
    }
    if(cnt != M) {
        cout << "No";
        return;
    }
    vector<int> sz;
    int cc=0;
    for(int i=1;i<=N;i++) if(!V[i]) {
        cc++;
        if(dfs(i)) {
            cout << "No";
            return;
        }
        sz.push_back(D[i]);
    }
    sort(all(sz));
    int s=1;
    for(int i=0;i<rt.size();i++) {
        int rr = rt[i],ss = sz[i] - 1;
        U[rr] = 1;
        for(;s<=rr && ss;s++) {
            if(U[s] == 0) U[s] = 1, --ss;
        }
        if(ss) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}