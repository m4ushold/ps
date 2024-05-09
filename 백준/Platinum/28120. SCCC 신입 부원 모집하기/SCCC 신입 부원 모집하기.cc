#include <bits/stdc++.h>
using namespace std;

const int MAX_V=22;
int N, K, X, A[MAX_V], B[MAX_V], vi[MAX_V];
vector<int> G[MAX_V], D[MAX_V];

bool dfs(int v) 
{
    vi[v]=1;
    for(int i:G[v]) {
        if(B[i]==-1 || !vi[B[i]] && dfs(B[i])) {
            A[v]=i, B[i]=v;
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K >> X;
    for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1;
    for(int i=1,n,a;i<=N;i++) {
        cin >> n;
        while(n--) {
            cin >> a;
            for(int j=0;j<X;j++) G[i].push_back((a-1)*X+j);
        }
    }
    vector<pair<int,int>> v;
    for(int i=1,a;i<=N;i++) {
        cin >> a;
        v.push_back({a,i});
    }
    sort(v.begin(),v.end(),greater<>());

    int cnt=0;
    for(auto [j,i]:v) {
        memset(vi,0,sizeof vi);
        cnt+=dfs(i);
    }

    for(int i=1;i<=N;i++) if(A[i]!=-1) D[A[i]/X].push_back(i);
    
    for(int i=0;i<K;i++) {
        cout << D[i].size() << ' ';
        for(int j:D[i]) cout << j << " ";
        cout << '\n';
    }
    return 0;
}