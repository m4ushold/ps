#include <bits/stdc++.h>
using namespace std;

int N, M, A[505][505];

bool chk(int x, int y) { return 0<min(x,y) && x<=N && y<=M; }

int s(int i, int j) {
    queue<tuple<int,int,int,int,int,int>> q;
    vector<pair<int,int>> v({{1,0},{-1,0},{0,1},{0,-1}});
    q.push({i,j,A[i][j],1,0,0});
    int mx=0;
    while(!q.empty()) {
        auto [x,y,res,d,px,py]=q.front(); q.pop();
        if(d==4) {mx=max(mx,res); continue;}
        for(auto [dx,dy]:v) if(chk(x+dx,y+dy) && !(x+dx==px && y+dy==py)) q.push({x+dx,y+dy,res+A[x+dx][y+dy],d+1,x,y});
    }
    return mx;
}

int t(int i, int j) {
    vector<pair<int,int>> d({{1,0},{-1,0},{0,1},{0,-1}}), v;
    for(auto [x,y]:d) if(chk(x+i,y+j)) v.push_back({x+i,y+j});
    int mx=0;
    for(int x=0;x<v.size();x++) for(int y=x+1;y<v.size();y++) for(int z=y+1;z<v.size();z++) 
        mx=max(mx,A[i][j]+A[v[x].first][v[x].second]+A[v[y].first][v[y].second]+A[v[z].first][v[z].second]);
    return mx;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j];
    int mx=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) mx=max({mx,s(i,j),t(i,j)});
    cout << mx;
    return 0;
}