#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using Point=pair<int,int>;

int L, A[303][303];
Point S, T;
vector<Point> V({{1,2}, {2,1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1,-2}, {-2,-1}});
bool bound(int i, int j) { return 0<=min(i,j) && max(i,j)<L; }

int bfs() {
    queue<pair<Point,int>> q;
    q.push({S, 0});
    while(!q.empty()) {
        auto [p, d]=q.front(); q.pop();
        A[p.x][p.y]=1;
        if(p.x==T.x && p.y==T.y) return d;
        for(auto [dx,dy]:V) if(bound(p.x+dx, p.y+dy) && !A[p.x+dx][p.y+dy]) A[p.x+dx][p.y+dy]=1, q.push({Point(p.x+dx,p.y+dy), d+1});
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> L >> S.x >> S.y >> T.x >> T.y;
        for(int i=0;i<L;i++) for(int j=0;j<L;j++) A[i][j]=0;
        cout << bfs() << '\n';
    }
    return 0;
}