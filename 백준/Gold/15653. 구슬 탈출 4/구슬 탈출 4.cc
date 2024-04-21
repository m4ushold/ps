#include <bits/stdc++.h>
using namespace std;
using Point=pair<int,int>;
using pos=pair<Point,Point>;

int N, M;
char A[11][11], B[11][11][11][11];
Point nxt[4][11][11], G;

void init() {
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(A[i][j]!='#') {
        Point a(i,j);
        while(A[a.first][a.second-1]=='.') a.second--;
        if(A[a.first][a.second-1]=='O') a.second--;
        nxt[0][i][j]=a;

        a={i,j};
        while(A[a.first][a.second+1]=='.') a.second++;
        if(A[a.first][a.second+1]=='O') a.second++;
        nxt[1][i][j]=a;

        a={i,j};
        while(A[a.first-1][a.second]=='.') a.first--;
        if(A[a.first-1][a.second]=='O') a.first--;
        nxt[2][i][j]=a;
        
        a={i,j};
        while(A[a.first+1][a.second]=='.') a.first++;
        if(A[a.first+1][a.second]=='O') a.first++;
        nxt[3][i][j]=a;
    }
}

int bfs(pos p) {
    queue<pair<pos,int>> q;
    q.push({p,0});
    while(!q.empty()) {
        auto [x,d]=q.front(); q.pop();
        auto [r,b]=x;
        if(r==G && b==G) continue;
        if(r==G) return d;
        if(B[r.first][r.second][b.first][b.second]) continue;
        B[r.first][r.second][b.first][b.second]=1;
        
        for(int i=0;i<4;i++) {
            Point nxtr=nxt[i][r.first][r.second], nxtb=nxt[i][b.first][b.second];
            
            if((r!=nxtr || b!=nxtb) && !B[nxtr.first][nxtr.second][nxtb.first][nxtb.second] && nxtr!=Point(0,0) && nxtb!=Point(0,0)) {
                if(nxtr==nxtb && nxtr!=G) {
                    if(i==0) r.second < b.second ? nxtb.second++ : nxtr.second++;
                    else if(i==1) r.second < b.second ? nxtr.second-- : nxtb.second--;
                    else if(i==2) r.first < b.first ? nxtb.first++ : nxtr.first++;
                    else if(i==3) r.first < b.first ? nxtr.first-- : nxtb.first--;
                }

                if((r!=nxtr || b!=nxtb) && nxtb!=G) q.push(make_pair(make_pair(nxtr,nxtb),d+1));
            }
                
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    Point r,b;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        cin >> A[i][j];
        if(A[i][j]=='R') r={i,j}, A[i][j]='.';
        else if(A[i][j]=='B') b={i,j}, A[i][j]='.';
        else if(A[i][j]=='O') G={i,j};
    }
    init();
    int a=bfs({r,b});
    cout << a;
    return 0;
}