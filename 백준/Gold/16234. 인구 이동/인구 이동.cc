#include <bits/stdc++.h>
using namespace std;

int N, L, R, A[55][55], B[55][55];
vector<pair<int,int>> v({{1,0},{0,1},{-1,0},{0,-1}});

bool bound(int x, int y) { return 1<=min(x,y) && max(x,y)<=N; }

pair<int,int> dfs0(int x, int y) {
    if(B[x][y]) return {0,0};
    B[x][y]=1;
    int a=A[x][y],b=1;
    for(auto [i,j]:v) if(bound(x+i, y+j) && !B[x+i][y+j] && L<=abs(A[x][y]-A[x+i][y+j]) && abs(A[x][y]-A[x+i][y+j])<=R) {
        auto [aa,bb]=dfs0(x+i,y+j);
        a+=aa, b+=bb;
    }
    return {a,b};
}

void dfs1(int x, int y, int n) {
    if(~B[x][y]&1) return;
    B[x][y]=2, A[x][y]=n;
    for(auto [i,j]:v) if(bound(x+i, y+j) && B[x+i][y+j]==1) {
        dfs1(x+i,y+j,n);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L >> R;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> A[i][j];
    int cnt=0;
    while(1) {
        for(int i=0;i<55;i++) for(int j=0;j<55;j++) B[i][j]=0;
        int c=0;
        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(!B[i][j]) {
            auto [s,n]=dfs0(i,j);
            dfs1(i,j,s/n), c++;
        }
        if(c==N*N) break;
        cnt++;
    }
    cout << cnt;
    return 0;
}