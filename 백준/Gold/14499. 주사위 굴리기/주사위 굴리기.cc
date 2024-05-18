#include <bits/stdc++.h>
using namespace std;

int N, M, X, Y, K, A[22][22];

struct Dice {
    int f, b, u, d, l, r;
    void roll(int dir) {
        if(dir==1) swap(u,r), swap(l,u), swap(d,l);
        else if(dir==2) swap(u,l), swap(r,u), swap(r,d);
        else if(dir==3) swap(u,b), swap(f,u), swap(f,d);
        else swap(u,f), swap(b,u), swap(b,d);
    }
} dice;

bool bound(int x, int y) {return 0<=min(x,y) && x<N && y<M;}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> X >> Y >> K;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) cin >> A[i][j];
    if(A[X][Y]) dice.d=A[X][Y], A[X][Y]=0;
    else A[X][Y]=dice.d;
    for(int i=0,a;i<K;i++) {
        cin >> a;
        if(a==1 && bound(X,Y+1)) {
            dice.roll(a);
            if(A[X][++Y]==0) A[X][Y]=dice.d;
            else dice.d = A[X][Y], A[X][Y]=0;
        }
        else if(a==2 && bound(X,Y-1)) {
            dice.roll(a);
            if(A[X][--Y]==0) A[X][Y]=dice.d;
            else dice.d = A[X][Y], A[X][Y]=0;
        }
        else if(a==3 && bound(X-1,Y)) {
            dice.roll(a);
            if(A[--X][Y]==0) A[X][Y]=dice.d;
            else dice.d = A[X][Y], A[X][Y]=0;
        }
        else if(a==4 && bound(X+1,Y)) {
            dice.roll(a);
            if(A[++X][Y]==0) A[X][Y]=dice.d;
            else dice.d = A[X][Y], A[X][Y]=0;
        }
        else continue;
        cout << dice.u << '\n';
    }
    return 0;
}