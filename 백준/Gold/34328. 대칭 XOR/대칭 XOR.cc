#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int bcnt(int x) {
    int cnt=0;
    while(x) {
        cnt+=x&1, x/=2;
    }
    return cnt;
}

void sol(int tc) {
    int n; cin >> n;
    if(n==1) {
        cout << 1;
        return;
    }
    if(bcnt(n+2) != 1) {
        cout << -1;
        return;
    }
    for(int i=0;i<n;i++) cout << i+1 << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}