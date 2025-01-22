#include <bits/stdc++.h>
using namespace std;

const int MAX_V=505;
int A[MAX_V], B[MAX_V], vi[MAX_V];
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

int matching() {
    int cnt=0;
    for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1;
    for(int i=0;i<MAX_V;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

void sol() {
    int n; cin >> n;
    for(int i=0;i<MAX_V;i++) G[i].clear();
    vector<tuple<int,char,string,string>> v(n);
    for(auto &[a,b,c,d]:v) cin >> a >> b >> c >> d;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
        auto [a,b,c,d]=v[i];
        auto [e,f,g,h]=v[j];
        if(abs(a-e)<=40 && b!=f && c==g && d!=h) {
            int aa=i, bb=j;
            if(b=='M') swap(aa,bb);
            G[aa].push_back(bb);
        }
    }
    cout << n-matching() << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}