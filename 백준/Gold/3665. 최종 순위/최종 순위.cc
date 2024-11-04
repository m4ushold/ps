#include <bits/stdc++.h>
using namespace std;

int N, A[505][505], IN[505], F;
vector<int> G[505];

vector<int> ts() {
    F=0;
    queue<int> q;
    vector<int> res;
    for(int i=1;i<=N;i++) if(!IN[i]) q.push(i);
    while(q.size()) {
        int v = q.front(); q.pop();
        if(q.size()) F=1;
        res.push_back(v);
        for(int i:G[v]) if(--IN[i] == 0) {
            q.push(i);
        }
    }

    if(res.size()!=N) F=2;
    reverse(res.begin(),res.end());
    return res;
}

void sol() {
    memset(A, 0, sizeof(A)), memset(IN, 0, sizeof(IN));
    for(int i=0;i<505;i++) G[i].clear();

    cin >> N;
    vector<int> v;
    for(int i=0,a;i<N;i++) {
        cin >> a;
        for(int j:v) A[a][j]=1, IN[j]++;
        v.push_back(a);
    }

    int m; cin >> m;
    for(int i=0,a,b;i<m;i++) {
        cin >> a >> b;
        if(!A[a][b]) swap(a,b);
        A[a][b]=0, A[b][a]=1;
        IN[b]--, IN[a]++;
    }
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(A[i][j]) G[i].push_back(j);
    auto res = ts();

    if(F==1) cout << "?";
    else if(F==2) cout << "IMPOSSIBLE";
    else for(int i:res) cout << i << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}