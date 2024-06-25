#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, T, D[101][101][22];
char A[101][101];
vector<pair<int,int>> v({{1,0}, {0,1}, {-1,0}, {0,-1}});
bool bound(int i, int j) {return 1<=min(i,j) && i<=N && j<=M; }

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> T;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j];
    int a,b,c,d; cin >> a >> b >> c >> d;
    D[a][b][0]=1;
    for(int t=1;t<=T;t++) {
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(A[i][j]=='.') {
            for(auto [dx,dy]:v) if(bound(i+dx,j+dy) && A[i+dx][j+dy]=='.') D[i+dx][j+dy][t]+=D[i][j][t-1];
        }
    }

    cout << D[c][d][T];
    return 0;
}