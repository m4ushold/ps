#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k;
    while(cin >> n >> m >> k && n) {
        int a=-1;
        for(int i=0;i<=n-m-k;i++) {
            if(m+i > n-m-i) { a=i; break; }
        }
        cout << a << "\n";
    }
    return 0;
}