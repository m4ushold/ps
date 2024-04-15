#include <bits/stdc++.h>
using namespace std;

int N, A[101][101], B[101][101];
void fill(int n) { for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) B[i][j]=A[i][j]<=n; }
bool bound(int i, int j) { return 1<=min(i,j) && max(i,j)<=N; }

void dfs(int i, int j) {
    B[i][j]=1;
    vector<pair<int,int>> v({{1,0},{0,1},{-1,0},{0,-1}});
    for(auto [x,y]:v) if(bound(i+x, j+y) && !B[i+x][j+y]) dfs(i+x, j+y);
}

int dfs() {
    int res=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(!B[i][j]) dfs(i,j), res++;
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int mn=1e9, mx=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> A[i][j], mn=min(mn,A[i][j]), mx=max(mx,A[i][j]);

    int dap=1;
    for(int i=mn;i<mx;i++) fill(i), dap=max(dap,dfs());
    cout << dap;
    return 0;
}