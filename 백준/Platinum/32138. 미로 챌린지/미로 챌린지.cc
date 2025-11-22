#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
// #define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N;
char A[101][101], B[101][101];
vector<pll> dir({
    {1,0},{0,1},{-1,0},{0,-1}
});
string D="URDL";

bool chk(int i, int j) {return 1<=min(i,j) && max(i,j)<=N;}

void stone() {
    cin >> N;
    int x,y;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        cin >> A[i][j];
        if(A[i][j] == 'G') x=i, y=j;
    }
    queue<pair<int,int>> q;
    q.push({x,y}), B[x][y]=1;
    while(q.size()) {
        auto [x,y] = q.front(); q.pop();
        for(auto [dx,dy]:dir) {
            int nx = x+dx, ny = y+dy;
            if(chk(nx, ny) && A[nx][ny] == '.' && !B[nx][ny]) {
                if(dx) A[nx][ny]='S';
                q.push({nx,ny});
                B[nx][ny]=1;
            }
        }
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) cout << A[i][j];
        cout << endl;
    }
}

void eka() {
    int px=-1,py=-1,pk=-1,pd=-1;
    int x,y,k,d;
    while(cin >> x >> y >> k && (x || y || k)) {
        if(x == px && y == py) d += 2;
        else if(pk == k) d = pd;
        else if(k) d=0;
        else d=1;
        cout << D[d] << endl;
        px = x, py = y, pk = k, pd = d;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    if(t==1) stone();
    else eka();
    return 0;
}