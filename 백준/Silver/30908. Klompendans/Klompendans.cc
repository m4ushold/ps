#include <bits/stdc++.h>
using namespace std;

int N, A[505][505], a,b,c,d;

bool bound(int x, int y) {return 1<=min(x,y) && max(x,y)<=N;}

void dfs(int x, int y, int f, int n) {
    if(A[x][y]&(1<<f)) return;
    A[x][y]|=1<<f;
    vector<pair<int,int>> 
        e({{a,b}, {a,-b}, {-a, b}, {-a, -b}, {b,a}, {b,-a}, {-b, a}, {-b, -a}}), 
        g({{c,d}, {c,-d}, {-c, d}, {-c, -d}, {d,c}, {d,-c}, {-d, c}, {-d, -c}}),
        v=f?e:g;

    for(auto [i,j]:v) {
        if(bound(x+i, y+j) && !(A[x+i][y+j]&(1<<(!f)))) dfs(x+i,y+j,!f,n);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> a >> b >> c >> d;
    dfs(1,1,0,1);
    dfs(1,1,1,2);

    int dap=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(A[i][j]) dap++;
    cout << dap;
    return 0;
}