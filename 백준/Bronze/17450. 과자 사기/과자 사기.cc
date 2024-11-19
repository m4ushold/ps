#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double mx = 0;
    int ans = 0;
    
    for (int i=0;i<3;i++) {
        int a,b; cin >> a >> b;
        int m = a*10 + (a*10>=5000 ? -500 : 0);
        if(b*10.0 / m > mx) {
            mx = b*10.0 / m;
            ans=i;
        }
    }
    cout << "SNU"[ans];
    return 0;
}