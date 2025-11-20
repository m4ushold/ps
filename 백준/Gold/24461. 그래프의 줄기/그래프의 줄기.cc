#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, D[101010];
vector<int> G[101010];

void sol(int tc) {
    cin >> N;
    for(int i=1;i<N;i++) {
        int a,b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<int> q;
    for(int i=0;i<N;i++) {
        D[i] = G[i].size();
        if(D[i] == 1) q.push(i), D[i]=0;
    }
    while(q.size() > 2) {
        queue<int> t;
        while(q.size()) {
            int v = q.front(); q.pop();
            for(int i:G[v]) if(D[i] && --D[i] == 1) {
                t.push(i);
                D[i]=0;
            }
        }
        q = t;
    }
    vector<int> v;
    while(q.size()) v.push_back(q.front()), q.pop();
    for(int i=0;i<N;i++) if(D[i]) v.push_back(i);
    sort(all(v));
    for(int i:v) cout << i << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}