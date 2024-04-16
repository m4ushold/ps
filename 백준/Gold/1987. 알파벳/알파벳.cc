#include <bits/stdc++.h>
using namespace std;
using Point=pair<int,int>;

int N, M;
char A[22][22];
vector<Point> V({{1,0},{0,1},{-1,0},{0,-1}});

int f(char c) { return 1<<(c-'A'); }
bool bound(int x, int y) { return 1<=min(x,y) && x<=N && y<=M; }

int dfs(int x=1, int y=1, int v=f(A[1][1])) {
    int res=__popcount(v);
    for(auto [i,j]:V) if(bound(x+i,y+j) && (v&f(A[x+i][y+j]))==0) res=max(res,dfs(x+i,y+j,v|f(A[x+i][y+j])));
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j];
    cout << dfs();
    return 0;
}