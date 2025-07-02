#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,h,w; cin >> n >> h >> w;
    for(int i=0;i<n;i++) {
        char a,b; cin >> a >> b;
        if(a == 'Y' || w == 0) cout << "Y ", h--, w++;
        else cout << "N ";

        if(b == 'Y' || h == 0) cout << "Y\n", w--, h++;
        else cout << "N\n";
    }
    return 0;
}