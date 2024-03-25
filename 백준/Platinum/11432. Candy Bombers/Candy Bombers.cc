#include <bits/stdc++.h>
using namespace std;

const int MAX_V=202;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V];
vector<int> G[MAX_V];

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
    int t; cin >> t;
    for(int j=1;j<=t;j++) {
        cin >> M >> N;
        for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1, G[i].clear();
        for(int i=1,n,a;i<=N;i++) {
            cin >> n;
            while(n--) cin >> a, G[i].push_back(a);
        }

        int cnt=0;
        for(int i=1;i<=N;i++) {
            for(int i=0;i<MAX_V;i++) vi[i]=0;
            cnt+=dfs(i);
        }
        cout << "Data Set " << j << ":\n" << cnt << "\n\n";
    }
    
    return 0;
}