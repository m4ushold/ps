#include <bits/stdc++.h>
using namespace std;
using Point=pair<int,int>;

struct robot_t {
    Point pos;
    int dir;
} robot;

int N, M, R, A[55][55];

Point nxt(Point p, int dir) {
    if(dir==0) return {p.first-1,p.second};
    else if(dir==1) return {p.first,p.second+1};
    else if(dir==2) return {p.first+1,p.second};
    return {p.first,p.second-1};
}

void run() {
    while(1) {
        auto &[x,y]=robot.pos;
        if(!A[x][y]) A[x][y]=2, R++;
        if(A[x+1][y] && A[x][y+1] && A[x-1][y] && A[x][y-1]) {
            auto [nx,ny] = nxt(robot.pos, (robot.dir+2)%4);
            if(A[nx][ny]==1) break;
            else x=nx, y=ny;
        } else {
            robot.dir=(robot.dir+3)%4;
            auto [nx,ny] = nxt(robot.pos, robot.dir);
            if(!A[nx][ny]) x=nx, y=ny;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    cin >> robot.pos.first >> robot.pos.second >> robot.dir;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) cin >> A[i][j];
    run();
    cout << R;

    return 0;
}