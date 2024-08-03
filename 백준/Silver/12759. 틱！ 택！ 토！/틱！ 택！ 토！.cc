#include <bits/stdc++.h>
using namespace std;

int A[5][5];

int f(int a, int b, int c) {return a && a==b && b==c;}

bool chk() {
    for(int i=1;i<=3;i++) {
        if(f(A[i][1], A[i][2], A[i][3])) return 1;
        if(f(A[1][i], A[2][i], A[3][i])) return 1;
    }
    if(f(A[1][1], A[2][2], A[3][3])) return 1;
    if(f(A[1][3], A[2][2], A[3][1])) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i=0,x,y;i<9;i++) {
        cin >> x >> y;
        A[x][y]=t;
        if(chk()) {cout << t; return 0;}
        t^=3;
    }
    cout << 0;

    return 0;
}