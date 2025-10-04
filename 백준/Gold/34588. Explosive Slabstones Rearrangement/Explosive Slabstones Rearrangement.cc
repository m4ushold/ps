#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;

int N, M, K, A[505][505];
int P[303030], S[303030];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

vector<pair<int,int>> dir(
    {{1,0},{0,1},{-1,0},{0,-1}}
);

int idx(int x, int y) {return (x-1)*M + y;}
bool chk(int x, int y) {return 1<=min(x,y) && x<=N && y<=M;}

void solve(){
    cin >> N >> M >> K;
    vector<pair<int,int>> v;
    for(int i=0;i<K;i++) {
        int x,y; cin >> x >> y;
        v.push_back({x,y});
        A[x][y]=i+1;
    }
    int a,b,c,d; cin >> a >> b >> c >> d;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        P[idx(i,j)]=idx(i,j);
        if(A[i][j]==0) {
            if(a<=i && i<=c && b<=j && j<=d) ;
            else S[idx(i,j)]=1;
        }
    }

    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(A[i][j]==0) {
        for(auto [dx,dy]:dir) if(chk(i+dx,j+dy) && A[i+dx][j+dy]==0) {
            Union(idx(i,j), idx(i+dx,j+dy));
        }
    }

    int mx=0;
    int cnt=0;
    for(int i=a;i<=c;i++) for(int j=b;j<=d;j++) if(A[i][j]) {
        mx=max(mx,A[i][j]);
        cnt++;
    }

    for(int i=a;i<c;i++) for(int j=b;j<=d;j++) {
        Union(idx(i,j), idx(i+1,j));
        if(j<d) Union(idx(i,j), idx(i,j+1));
    }

    if(cnt==0) {
        cout << 0;
        return;
    }
    
    int num=0;

    for(auto [x,y]:v) {
        ++num;
        for(auto [dx,dy]:dir) if(chk(x+dx,y+dy)) {
            if(A[x+dx][y+dy] <= num) {
                Union(idx(x,y), idx(x+dx,y+dy));
            }
        }
        if(S[Find(idx(a,b))] >= cnt) {
            cout << max(num,mx) << '\n';
            return;
        }
    }
    cout << -1;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}