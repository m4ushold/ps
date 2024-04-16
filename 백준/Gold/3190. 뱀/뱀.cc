#include <bits/stdc++.h>
using namespace std;
using Point=pair<int,int>;

int N, K, L, A[111][111], X=1, Y=1, D=1, T=0, S=1;
char DIR[20202];
queue<Point> Q;

void nxt() {
    if(D==0) X--;
    else if(D==1) Y++;
    else if(D==2) X++;
    else Y--;
}

void turn(char c) { if(c) D=(D+(c=='L'?3:1))%4; }

int run() {
    turn(DIR[T]), nxt();
    if(A[X][Y]==2) return 0;

    S+=A[X][Y], A[X][Y]=2, Q.push({X,Y});
    if(Q.size() > S) {
        auto [x,y]=Q.front();
        A[x][y]=0, Q.pop();
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=0,s,e;i<K;i++) cin >> s >> e, A[s][e]++;
    for(int i=0;i<=N+1;i++) A[0][i]=A[i][0]=A[N+1][i]=A[i][N+1]=2;

    cin >> L;
    for(int i=0,t,f;i<L;i++) {
        char c; cin >> t >> c;
        DIR[t]=c;
    }
    
    Q.push({1,1}), A[1][1]=2;
    while(run()) T++;
    cout << T+1;
    return 0;
}