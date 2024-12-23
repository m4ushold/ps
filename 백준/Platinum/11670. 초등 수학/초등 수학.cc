#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MAX_V=101010;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V];
vector<int> G[MAX_V];

bool dfs(int v)  {
    vi[v]=1;
    for(int i:G[v]) {
        if(B[i]==-1 || !vi[B[i]] && dfs(B[i])) {
            A[v]=i, B[i]=v;
            return 1;
        }
    }
    return 0;
}

int matching(int n) {
    int cnt=0;
    for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1;
    for(int i=1;i<=n;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<array<ll,2>> v(n);
    vector<ll> x;
    for(auto &[a,b]:v) {
        cin >> a >> b;
        for(auto j:{a+b,a-b,a*b}) x.push_back(j);
    }
    sort(x.begin(),x.end());
    x.erase(unique(x.begin(),x.end()),x.end());

    int idx=0;
    for(auto &[a,b]:v) {
        ++idx;
        for(auto j:{a+b,a-b,a*b}) {
            G[idx].push_back(lower_bound(x.begin(),x.end(),j)-x.begin());
        }
    }

    if(matching(n) != n) return cout << "impossible", 0;
    idx=0;
    for(auto [a,b]:v) {
        ++idx;
        cout << a;
        if(a+b == x[A[idx]]) cout << " + ";
        else if(a-b == x[A[idx]]) cout << " - ";
        else cout << " * ";
        cout << b << " = " << x[A[idx]] << '\n';
    }
    return 0;
}