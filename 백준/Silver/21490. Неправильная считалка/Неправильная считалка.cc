#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll A[1010];

void sol(int tc) {
    ll n,k; cin >> n >> k;
    ll x=0;
    while(!A[x]) {
        A[x]=1;
        x=(x+k)%n;
    }
    int cnt=0;
    for(int i=0;i<n;i++) if(!A[i]) cnt++;
    cout << cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}