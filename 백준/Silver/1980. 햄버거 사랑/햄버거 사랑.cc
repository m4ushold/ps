#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,t; cin >> n >> m >> t;
    int h=0, c=1e9;
    for(int i=0;i*n<=t;i++) {
        int j=(t-i*n)/m;
        int cc = t-i*n-j*m;
        if(c > cc) c=cc, h=i+j;
        else if(c==cc) h=max(h, i+j);
    }
    cout << h << ' ' << c;
    return 0;
}