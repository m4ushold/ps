#include <bits/stdc++.h>
using namespace std;

int N, M, B[55][55][55][55];
char A[101][101];
array<int,5> P[55][55][55][55];
vector<array<int,3>> dir({
    {1,0,'S'},{0,1,'E'},{0,-1,'W'},{-1,0,'N'},
});

pair<int,int> nxt(int x, int y, int dx, int dy) {
    x+=dx, y+=dy;
    if(x<1) x=N;
    if(x>N) x=1;
    if(y<1) y=M;
    if(y>M) y=1;
    return {x,y};
}

pair<int,int> prv(int x, int y, char d) {
    if(d=='S') x--;
    else if(d=='E') y--;
    else if(d=='W') y++;
    else x++;
    if(x<1) x=N;
    if(x>N) x=1;
    if(y<1) y=M;
    if(y>M) y=1;
    return {x,y};
}

string bfs(int a, int b, int c, int d) {
    queue<array<int,4>> q;
    q.push({a,b,c,d});
    B[a][b][c][d]=1;
    int x=0,y=0,xx=0,yy=0;
    while(q.size()) {
        auto [a,b,c,d]=q.front(); q.pop();

        if(a==c && b==d) {
            x=a,y=b,xx=c,yy=d;
            break;
        }

        for(auto i:dir) {
            auto [aa,bb] = nxt(a,b,i[0],i[1]);
            auto [cc,dd] = nxt(c,d,i[0],i[1]);
            if(A[aa][bb] == 'G') continue;
            else if(A[aa][bb] == 'X') aa=a,bb=b;
            if(A[cc][dd] == 'G') continue;
            else if(A[cc][dd] == 'X') cc=c,dd=d;
            if(B[aa][bb][cc][dd]) continue;
            B[aa][bb][cc][dd]=1;
            P[aa][bb][cc][dd]={a,b,c,d,i[2]};
            q.push({aa,bb,cc,dd});
        }
    }

    string res;
    if(x==0) return res;
    while(x!=a || y!=b || xx!=c || yy!=d) {
        auto [aa,bb,cc,dd,e] = P[x][y][xx][yy];
        res+=e;
        x=aa,y=bb,xx=cc,yy=dd;
    }
    reverse(res.begin(),res.end());
    return res;
}

void sol() {
    cin >> N >> M;
    vector<int> v;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        cin >> A[i][j];
        if(A[i][j] == 'P') v.push_back(i), v.push_back(j), A[i][j]='.';
    }
    memset(B, 0, sizeof(B)), memset(P, 0, sizeof(P));
    auto [x,y] = nxt(1,1,-1,0);
    // cout << x << ' ' << y << endl;
    auto s = bfs(v[0], v[1], v[2], v[3]);
    if(s.empty()) cout << "IMPOSSIBLE\n";
    else cout << s.size() << ' ' << s << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}