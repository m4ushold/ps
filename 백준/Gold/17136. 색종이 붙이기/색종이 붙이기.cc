#include <bits/stdc++.h>
using namespace std;

int A[11][11], C[6]={0,5,5,5,5,5}, R=1e9;

void fill(int x, int y, int sz, int f) { for(int i=x;i<x+sz;i++) for(int j=y;j<y+sz;j++) A[i][j]=f; }

bool chk(int x, int y, int sz, int f) {
    if(x+sz > 11 || y+sz > 11) return 0;
    for(int i=x;i<x+sz;i++) for(int j=y;j<y+sz;j++) if(A[i][j]!=f) return 0;
    return 1;
}

void f(int cnt=0) {
    if(cnt > R || chk(1,1,10,0)) {
        R=min(R,cnt);
        return ;
    }
    
    for(int i=1;i<=10;i++) for(int j=1;j<=10;j++) if(A[i][j]) {
        for(int sz=1;sz<=5;sz++) if(C[sz] && chk(i,j,sz,1)) {
            C[sz]--, fill(i,j,sz,0);
            f(cnt+1);
            C[sz]++, fill(i,j,sz,1);
        }
        return;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=1;i<=10;i++) for(int j=1;j<=10;j++) cin >> A[i][j];
    f();
    cout << (R==(int)1e9 ? -1 : R);
    return 0;
}