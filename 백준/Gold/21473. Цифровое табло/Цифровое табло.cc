#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int K, D, W, H, N, A[2020][2020];
int gcd(int a, int b) {return b?gcd(b,a%b):a;}

vector<pii> dir({
    {1,0},{0,1},{-1,0},{0,-1}
});

bool chk(int x, int y) {
    return 0<=min(x,y) && x<(H-1)*(K-1)+H && y<(W-1)*(K-1)+W;
}

void sol(int tc) {
    cin >> K >> D >> W >> H >> N;
    vector<pair<pii,pii>> v(N);
    queue<array<int,3>> q;
    for(auto &[s,e]:v) {
        cin >> s.second >> s.first >> e.second >> e.first;
        s.first*=K, s.second*=K, e.first*=K, e.second*=K;
        int dx = e.first-s.first, dy = e.second-s.second, g = abs(gcd(dx,dy));
        dx/=g,dy/=g;
        while(s!=e) {
            q.push({s.first,s.second,0});
            A[s.first][s.second]=1;
            s.first+=dx, s.second+=dy;
        }
        q.push({e.first,e.second,0});
        A[s.first][s.second]=1;
    }

    while(q.size()) {
        auto [x,y,d] = q.front(); q.pop();
        for(auto [dx,dy]:dir) if(chk(x+dx,y+dy) && !A[x+dx][y+dy] && d<D-1) {
            q.push({x+dx,y+dy,d+1});
            A[x+dx][y+dy]=1;
        }
    }

    for(int i=0;i<(H-1)*(K-1)+H;i++) {
        for(int j=0;j<(W-1)*(K-1)+W;j++) cout << (char)(A[i][j]?'*':'.');
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}