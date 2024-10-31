#include <bits/stdc++.h>
using namespace std;

int N, M;
char A[333][333], B[333][333];
vector<pair<int,int>> d({
    {1,0}, {0,1}, {-1,0}, {0,-1}
});
bool chk(int x, int y) {return 0<min(x,y) && x<=N && y<=M;}

pair<int,int> dfs(int x, int y) {
    int a=0,b=0;
    B[x][y]=1;
    if(A[x][y]=='o') a++;
    else if(A[x][y]=='v') b++;
    for(auto [dx,dy]:d) if(chk(x+dx,y+dy) && !B[x+dx][y+dy] && A[x+dx][y+dy]!='#') {
        auto [c,d] = dfs(x+dx,y+dy);
        a+=c, b+=d;
    }
    return {a,b};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j];
    int a=0, b=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(A[i][j]!='#' && !B[i][j]) {
        auto [c,d] = dfs(i,j);
        if(c > d) a+=c;
        else b+=d;
    }
    cout << a << ' ' << b;
    return 0;
}