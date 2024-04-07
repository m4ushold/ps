#include <bits/stdc++.h>
using namespace std;

int N, M;
char A[55][55];

bool chk(int x, int y, int s) { 
    if(x+s>N || y+s>M) return 0;
    return A[x][y]==A[x][y+s] && A[x][y+s]==A[x+s][y] && A[x+s][y]==A[x+s][y+s]; 
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j];
    int mx=1;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        for(int s=1;s<min(N,M);s++) if(chk(i,j,s)) mx=max(mx,s+1);
    }
    cout << mx*mx;
    return 0;
}