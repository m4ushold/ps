#include <bits/stdc++.h>
using namespace std;

int s(int n) {
    int ret=0;
    while(n) ret+=n%10, n/=10;
    return ret;
}

bool singi(int n) { return n%s(n) == 0; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int cnt=0;
    for(int i=1;i<=n;i++) if(singi(i)) cnt++;
    cout << cnt;
    return 0;
}