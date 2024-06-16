#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n,d,cnt=0; cin >> n >> d;
        for(int i=0;i<n;i++) {
            double v,f,c; cin >> v >> f >> c;
            if(v*f/c>=d) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}