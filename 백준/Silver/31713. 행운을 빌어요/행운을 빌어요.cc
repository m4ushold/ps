#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int a,b; cin >> a >> b;
        if(3*a<=b && b<=4*a) cout << "0\n";
        else if(b<3*a) cout << 3*a-b << '\n';
        else {
            int ans=0;
            if(b<3) ans=b=3-b;
            else if(b==5) ans=1,b=6;
            while(a*4<b) ans++,a++;
            cout << ans << '\n';
        }
    }
    return 0;
}