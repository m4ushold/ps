#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll INF=(1e18);
vector<tuple<int,int,int,int>> qry;
ll N, M, Q, A[5][101010], B[5][101010], R[101010];
vector<pair<int,int>> dir({{1,0},{0,1},{-1,0},{0,-1}});
priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<>> pq;

bool bound(int x, int y, int l, int r) {return 0<=x && x<N && l<=y && y<=r;}
void sp(int i, int j, int l, int r) {
    for(int x=0;x<N;x++) for(int y=l;y<=r;y++) B[x][y]=INF;
    pq.push({A[i][j],i,j}), B[i][j]=A[i][j];
    while(pq.size()) {
        auto [c,x,y]=pq.top(); pq.pop();
        if(B[x][y]<c) continue;
        for(auto [dx,dy]:dir) {
            int nx=x+dx, ny=y+dy;
            if(bound(nx, ny, l, r) && B[nx][ny] > c + A[nx][ny]) {
                B[nx][ny] = c + A[nx][ny];
                pq.push({B[nx][ny],nx,ny});
            }
        }
    }
}

void dnc(vector<int> &v, int l, int r) {
    if(v.empty() || l>r) return;
    int m=l+r>>1;
    for(int i=0;i<N;i++) {
        sp(i,m,l,r);
        for(int j:v) {
            auto [x,y,xx,yy] = qry[j];
            R[j] = min(R[j], B[x][y] + B[xx][yy] - A[i][m]);
        }
    }
    vector<int> lq, rq;
    for(int i:v) {
        auto [x,y,xx,yy]=qry[i];
        if(yy<m) lq.push_back(i);
        if(y>m) rq.push_back(i);
    }
    dnc(lq,l,m-1), dnc(rq,m+1,r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) cin >> A[i][j];
    cin >> Q;
    vector<int> v;
    for(int i=0,a,b,c,d;i<Q;i++) {
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        if(b>d) swap(a,c), swap(b,d);
        qry.emplace_back(a,b,c,d);
        v.push_back(i);
        R[i]=INF;
    }
    dnc(v,0,M-1);
    for(int i=0;i<Q;i++) cout << R[i] << '\n';
    return 0;
}