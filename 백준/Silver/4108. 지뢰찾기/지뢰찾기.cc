#include <bits/stdc++.h>
using namespace std;

int N, M;
char A[111][111];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin >> N >> M && N) {
        for(int i=1;i<=100;i++) for(int j=1;j<=100;j++) A[i][j]=0;
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j];
        vector<pair<int,int>> v({{0,1},{1,1},{1,0},{-1,0},{-1,-1},{0,-1},{1,-1},{-1,1}});
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(A[i][j]=='.') {
            A[i][j]='0';
            for(auto [x,y]:v) if(A[i+x][j+y]=='*') A[i][j]++;
        }
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=M;j++) cout << A[i][j];
            cout << '\n';
        }
    }
    return 0;
}