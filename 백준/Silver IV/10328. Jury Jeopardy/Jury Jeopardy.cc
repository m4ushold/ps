#include <bits/stdc++.h>
using namespace std;

char A[202][202];

void move(int &x, int &y, int dir) {
    if(!dir) ++x;
    else if(dir==1) ++y;
    else if(dir==2) --x;
    else if(dir==3) --y;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t, cout << t << '\n';
    while(t--) {
        for(int i=0;i<202;i++) for(int j=0;j<202;j++) A[i][j]='#';
        int x=100, y=100, mnw=x, mxw=x, mnh=y, mxh=y;
        int dir=0;
        string s; cin >> s;
        for(char c:s) {
            if(c=='F') move(x,y,dir);
            else if(c=='R') dir=(dir+1)%4, move(x,y,dir);
            else if(c=='L') dir=(dir+3)%4, move(x,y,dir);
            else if(c=='B') dir=(dir+2)%4, move(x,y,dir);
            A[y][x]='.';
            mnw=min(mnw, x), mxw=max(mxw, x);
            mnh=min(mnh, y), mxh=max(mxh, y);
        }
        
        cout << mxh-mnh+3 << ' ' << mxw-mnw+2 << '\n';
        for(int i=mnh-1;i<=mxh+1;i++) {
            for(int j=mnw;j<=mxw+1;j++) cout << A[i][j];
            cout << '\n';
        }
    }
    return 0;
}