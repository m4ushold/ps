#include <bits/stdc++.h>
using namespace std;

const int MAX_V=20202;
int N, K, A[MAX_V], B[MAX_V], vi[MAX_V];
vector<int> G[MAX_V];

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

int matching() {
    int cnt=0;
    for(int i=1;i<=N;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1;
    string s; cin >> s;
    for(int i=0;i<N;i++) {
        if(s[i]=='H') {
            for(int j=max(i-K,0);j<min(i+K+1,N);j++) if(s[j]=='P') G[i+1].push_back(j+1);
        }
    }
    cout << matching();
    return 0;
}