#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a,b,n,w; cin >> a >> b >> n >> w;
    int aa=0, cnt=0;
    for(int i=1;i<n;i++) if(a*i+b*(n-i) == w) {
        aa=i, cnt++;
    }
    if(cnt==1) cout << aa << ' ' << n-aa;
    else cout << -1;
    return 0;
}