#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int R, C, B[1515][1515], P[1515*1515];
char A[1515][1515];

vector<pair<int,int>> dir({{1,0}, {0,1}, {-1,0}, {0,-1}}), stk;

int f(int i, int j) {return i*C+j;}
pair<int,int> fi(int x) {return {x/C, x%C};}
bool bound(int i, int j) {return 0<=min(i,j) && i<R && j<C;}
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) { return Find(u)!=Find(v) && (P[P[u]]=P[v], true); }

void dfs(int i, int j) {
    if(B[i][j]) return;
    B[i][j]=1;
    if(A[i][j]=='X') {stk.push_back({i,j}); return;}
    for(auto [x,y]:dir) if(bound(i+x, j+y) && !B[i+x][j+y]) dfs(i+x, j+y), Union(f(i,j), f(i+x,j+y));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    iota(P, P+1515*1515, 0);
    vector<int> v;
    for(int i=0;i<R;i++) for(int j=0;j<C;j++) {
        cin >> A[i][j];
        if(A[i][j]!='X') stk.push_back({i,j});
        if(A[i][j]=='L') v.push_back(f(i,j));
    }
    int a=v[0], b=v[1], t=0;
    
    while(Find(a)!=Find(b)) {
        vector<pair<int,int>> cur=stk;
        stk.clear();

        for(auto [i,j]:cur) {
            A[i][j]='.', B[i][j]=0;
            for(auto [x,y]:dir) if(bound(i+x, j+y) && A[i+x][j+y]=='.') Union(f(i,j), f(i+x,j+y));
        }
        if(Find(a)==Find(b)) break;
        for(auto [i,j]:cur) if(!B[i][j]) dfs(i,j);
        t++;
    }
    cout << t;
    return 0;
}