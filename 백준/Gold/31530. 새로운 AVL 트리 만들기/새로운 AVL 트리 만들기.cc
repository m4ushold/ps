#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int MOD=1e9+7;
ll D[1010101][3]; // 2,0 2,1 3

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    D[1][0]=D[1][1]=D[1][2]=1;
    D[2][0]=D[2][1]=2;
    D[2][2]=3;
    for(int i=3;i<1010101;i++) {
        D[i][0]=D[i-1][0]*((D[i-1][0]+D[i-2][0])%MOD)%MOD;
        D[i][1]=D[i-1][1]*D[i-2][1]%MOD*2%MOD;
        D[i][2]=(D[i-1][2]*D[i-2][2]%MOD*2%MOD + (D[i-1][2]*D[i-1][2])%MOD)%MOD;
    }
    int t; cin >> t;
    while(t--) {
        int h,s; cin >> h >> s;
        if(s==1) {
            int a; cin >> a;
            cout << "1\n";
        }
        else if(s==3) {
            int a; cin >> a >> a >> a;
            cout << D[h][2] << '\n';
        }
        else {
            int a,b; cin >> a >> b;
            if(a+b) cout << D[h][0] << '\n';
            else cout << D[h][1] << '\n';
        }
    }
    return 0;
}