#include <bits/stdc++.h>
using namespace std;

const int MAX_V=1010;
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=0,n,x;i<N;i++) {
        cin >> n;
        while(n--) cin >> x, G[x].push_back(i+1);
    }

    int cnt=0;
    for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1;
    for(int i=1;i<1010;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
        if(cnt==N) return cout << i+1, 0;
    }
    return 0;
}