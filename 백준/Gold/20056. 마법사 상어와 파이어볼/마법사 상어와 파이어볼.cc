#include <bits/stdc++.h>
using namespace std;

struct fireball {
    int x,y,m,s,d;
};

int N, M, K;
vector<fireball> MP[55][55], T[55][55];
vector<pair<int,int>> dir({
    {-1,0},{-1,1},{0,1},{1,1},
    {1,0},{1,-1},{0,-1},{-1,-1}
});

int f(int x) {
    while(x<=0) x+=N;
    while(x>N) x-=N;
    return x;
}

void move() {
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        for(auto &[x,y,m,s,d]:MP[i][j]) {
            x+=dir[d].first*s, y+=dir[d].second*s;
            x=f(x), y=f(y);
            T[x][y].push_back(fireball{x,y,m,s,d});
        }
    }
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(T[i][j].size()>1) {
        int m=0,s=0,d=0;
        for(auto fb:T[i][j]) m+=fb.m, s+=fb.s, d|=1<<(fb.d&1);
        m/=5, s/=T[i][j].size();
        T[i][j].clear();
        if(m) {
            if(d==3) {
                for(int dd:{1,3,5,7}) T[i][j].push_back(fireball{i,j,m,s,dd});
            } else {
                for(int dd:{0,2,4,6}) T[i][j].push_back(fireball{i,j,m,s,dd});
            }
        }
    }

    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        MP[i][j]=T[i][j];
        T[i][j].clear();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for(int i=0;i<M;i++) {
        int x,y,m,s,d; cin >> x >> y >> m >> s >> d;
        MP[x][y].push_back(fireball{x,y,m,s,d});
    }
    while(K--) move();

    int dap=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        for(auto f:MP[i][j]) dap+=f.m;
    }
    cout << dap;
    return 0;
}