#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,a,b; cin >> n >> a >> b;
    a=66-a, b=130-b;
    for(int i=0,x,y;i<8-n;i++) {
        cin >> x >> y;
        x=min(x,6), a-=3*x, b-=3*x;
        b-=3*min(6-x,y);
    }
    cout << (a>0 || b>0 ? "Nae ga wae" : "Nice");
    return 0;
}