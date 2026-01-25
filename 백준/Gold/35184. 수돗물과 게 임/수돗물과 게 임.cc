#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll = pair<ll,ll>;

char A[505][505];
ll N, M, T, D[505][505][4];
vector<pll> dir({
    {-1,0},{0,-1},{1,0},{0,1}
});

bool chk(int x, int y) {
    return 1<=min(x,y) && x<=N && y<=M;
}

void fn(priority_queue<array<ll,4>,vector<array<ll,4>>,greater<>> &pq, int i, int j, int d, int ii, int jj, int dd, int w) {
    if(D[i][j][d] + w < D[ii][jj][dd]) {
        D[ii][jj][dd] = D[i][j][d] + w;
        pq.push({D[ii][jj][dd],ii,jj,dd});
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> T;
    array<int,3> s;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin >> A[i][j];
            for(int k=0;k<4;k++) D[i][j][k] = LLONG_MAX/4;
            if(isdigit(A[i][j])) {
                s = {i,j,A[i][j]-'0'};
                A[i][j] = '.';
                D[i][j][s[2]] = 0;
            }
        }
    }
    
    priority_queue<array<ll,4>,vector<array<ll,4>>,greater<>> pq;
    pq.push({0,s[0],s[1],s[2]});
    while(pq.size()) {
        auto [c,i,j,d] = pq.top(); pq.pop();
        if(A[i][j] == 'S') {
            cout << D[i][j][d];
            return 0;
        } else if(A[i][j] == '.') {
            fn(pq,i,j,d,i,j,(d+1)%4,T);
            for(int k=0;k<4;k++) if((d^k)&1) {
                auto [dx,dy] = dir[k];
                if(chk(i+dx,j+dy)) {
                    fn(pq,i,j,d,i+dx,j+dy,d,1);
                }
            }
        } else if(A[i][j] == 'T') {
            int dd = (d+1)%4;
            auto [dx,dy] = dir[dd];
            if(chk(i+dx,j+dy)) {
                fn(pq,i,j,d,i+dx,j+dy,dd,0);
            }
        }
    }
    cout << -1;
    return 0;
}