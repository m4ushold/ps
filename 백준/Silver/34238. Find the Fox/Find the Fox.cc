#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int N, M;
char A[101][101];
vector<pair<int,int>> dir({
    {1,0},{0,1},{-1,0},{0,-1},
    {1,1},{1,-1},{-1,1},{-1,-1}
});
 
bool chk(int x, int y) {return 1<=min(x,y) && x<=N && y<=M;}
 
void sol(int tc) {
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j];
 
    int cnt=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(A[i][j] == 'F') {
        for(auto [dx,dy]:dir) if(chk(i+dx,j+dy) && chk(i+2*dx,j+2*dy) && A[i+dx][j+dy]=='O' && A[i+2*dx][j+2*dy]=='X') {
            cnt++;
        }
    }
    cout << cnt;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}