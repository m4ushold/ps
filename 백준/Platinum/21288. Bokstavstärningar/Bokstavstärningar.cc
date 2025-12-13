#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

const int MAX_V=1010;
int N, M, K, A[MAX_V], B[MAX_V], vi[MAX_V];
vector<int> G[MAX_V];
set<char> D[22];

bool dfs(int v) {
    vi[v]=1;
    for(int i:G[v]) {
        if(B[i]==-1 || !vi[B[i]] && dfs(B[i])) {
            A[v]=i, B[i]=v;
            return 1;
        }
    }
    return 0;
}

int bi_matching() {
    int cnt=0;
    for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1;
    for(int i=1;i<=N;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

void sol(int tc) {
    cin >> N >> K >> M;
    for(int i=1;i<=N;i++) {
        string s; cin >> s;
        for(char c:s) D[i].insert(c);
    }

    int ans=0;
    for(int i=1;i<=M;i++) {
        string s; cin >> s;
        for(int i=1;i<=N;i++) G[i].clear();
        for(int j=0;j<N;j++) for(int k=1;k<=N;k++) {
            if(D[k].count(s[j])) G[j+1].push_back(k);
        }
        ans += bi_matching() == N;
    }
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}