#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, A[22], B[22], M[22][22];
vector<pair<int,int>> C[2];

int b(int f, int i=0, int d=0) {
    if(i == C[f].size()) {
        return d;
    }
    int res=0;
    auto [x,y] = C[f][i];
    
    res=max(res,b(f,i+1,d));

    if(M[x][y] && !A[x+y] && !B[x-y+N]) {
        A[x+y]=1, B[x-y+N]=1;
        res=max(res,b(f,i+1,d+1));
        A[x+y]=0, B[x-y+N]=0;
    }
    return res;
}

void sol(int tc) {
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        cin >> M[i][j];
        C[(i+j)&1].push_back({i,j});
    }
    int ans=0;
    ans+=b(0);
    memset(A, 0, sizeof(A)), memset(B, 0, sizeof(B));
    ans+=b(1);
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}