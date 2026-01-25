#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll=long long;
using pll = pair<ll,ll>;

int N, P[101010], S[101010], D[101010], X[101010];
vector<int> G[101010];
set<int> A[101010];

int dfs(int v=1, int p=-1) {
    S[v]=1;
    int mx=D[v];
    for(int i:G[v]) if(i != p) {
        D[i] = D[v]+1;
        int a = dfs(i,v);
        mx = max(mx, a);
        X[v] = max(X[v], a - D[v]+1);
        S[v] += S[i];
    }
    return mx;
}

int ddfs(int v=1, int p=-1) {
    vector<int> vec;
    for(int i:G[v]) if(i != p) {
        vec.push_back(ddfs(i,v));
    }
    int res=v;
    if(vec.size()) {
        sort(vec.begin(),vec.end(),[&](int a, int b) {
            return A[a].size() > A[b].size();
        });

        auto &ss = A[vec[0]];
        for(int i=1;i<vec.size();i++) {
            for(int j:A[vec[i]]) {
                if(ss.count(N/2 - j)) {
                    cout << 2;
                    exit(0);
                }
            }
            for(int j:A[vec[i]]) ss.insert(j);
        }
        res = vec[0];
    }
    if(S[v] < N/2) A[res].insert(S[v]);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=2;i<=N;i++) {
        cin >> P[i];
        G[P[i]].push_back(i);
    }
    dfs();
    for(int i=1;i<=N;i++) {
        if(S[i] == N/2) {
            cout << X[i];
            return 0;
        }
    }
    ddfs();
    cout << 0 << endl;
    return 0;
}