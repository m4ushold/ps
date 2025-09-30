#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, M, T, A[101][101];
vector<pll> dir({
    {1,0},{0,1},{0,-1},{-1,0},
    {1,1},{1,-1},{-1,1},{-1,-1}
});

void sol(int tc) {
    cin >> N >> M >> T;
    queue<pll> q;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            char c; cin >> c;
            A[i+30][j+30]=c=='#';
            if(A[i+30][j+30]) q.push({i+30,j+30});
        }
    }
    while(q.size()) {
        auto [x,y]=q.front(); q.pop();
        if(A[x][y]==min<ll>(22,T+1)) continue;
        for(auto [dx,dy]:dir) if(A[x+dx][y+dy]==0) {
            A[x+dx][y+dy]=A[x][y]+1;
            q.push({x+dx,y+dy});
        }
    }

    ll ans=0;
    for(int i=0;i<101;i++) for(int j=0;j<101;j++) ans+=!!A[i][j];
    if(T<=22) {
        cout << ans;
    } else {
        ll cc=0;
        for(int i=1;i<100;i++) for(int j=1;j<100;j++) if(A[i][j]==22) {
            cc++;
        }
        T-=21;
        if(ans) ans += 8*(T*(T+1))/2 + cc*T;
        cout << ans;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}