#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> D({
    {0,-1}, {-1,-1}, {-1,0}, {-1,1},
    {0,1}, {1,1}, {1,0}, {1,-1}
}), SD({
    {-1,0}, {0,-1}, {1,0}, {0,1}
});

bool chk(int x, int y) {return 0<=min(x,y) && max(x,y)<4;}

int M, S, SEA[4][4][8], TMP[4][4][8], SMELL[4][4]; // x y d

struct {
    int x, y;
} shark;

void nojam() {
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) for(int k=0;k<8;k++) TMP[i][j][k]=SEA[i][j][k], SEA[i][j][k]=0;

    for(int i=0;i<4;i++) for(int j=0;j<4;j++) for(int k=0;k<8;k++) {
        int f=1;
        for(int d=0;d<8;d++) {
            int nd=(k-d+8)%8, nx=i+D[nd].first, ny=j+D[nd].second;
            if(chk(nx, ny) && !SMELL[nx][ny] && (nx!=shark.x || ny!=shark.y)) {
                SEA[nx][ny][nd]+=TMP[i][j][k];
                f=0;
                break;
            }
        }
        if(f) SEA[i][j][k]+=TMP[i][j][k];
    }
    
    vector<int> path;
    int mx=-1;
    for(int a=0;a<4;a++) for(int b=0;b<4;b++) for(int c=0;c<4;c++) {
        int x=shark.x, y=shark.y, cnt=0;
        set<pair<int,int>> tmp;

        x+=SD[a].first, y+=SD[a].second;
        if(!chk(x,y)) continue;
        tmp.insert({x,y});
        
        x+=SD[b].first, y+=SD[b].second;
        if(!chk(x,y)) continue;
        tmp.insert({x,y});

        x+=SD[c].first, y+=SD[c].second;
        if(!chk(x,y)) continue;
        tmp.insert({x,y});
        
        for(auto [i,j]:tmp) for(int d=0;d<8;d++) cnt+=SEA[i][j][d];
        if(cnt > mx) {
            mx = cnt;
            path = vector<int>({a,b,c});
        }
    }

    for(int d:path) {
        shark.x+=SD[d].first, shark.y+=SD[d].second;
        int cnt=0;
        for(int i=0;i<8;i++) cnt+=SEA[shark.x][shark.y][i], SEA[shark.x][shark.y][i]=0;
        if(cnt) SMELL[shark.x][shark.y] = 3;
    }

    for(int i=0;i<4;i++) for(int j=0;j<4;j++) SMELL[i][j]=max(SMELL[i][j]-1, 0);
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) for(int k=0;k<8;k++) SEA[i][j][k]+=TMP[i][j][k];
}

int count() {
    int res=0;
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) for(int k=0;k<8;k++) res+=SEA[i][j][k];
    return res;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> M >> S;
    for(int i=0,x,y,d;i<M;i++) {
        cin >> x >> y >> d;
        SEA[x-1][y-1][d-1]++;
    }
    
    cin >> shark.x >> shark.y;
    shark.x--, shark.y--;
    while(S--) nojam();
    
    cout << count() << '\n';
    return 0;
}