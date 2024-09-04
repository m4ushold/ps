#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, D[1515151];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ll mx=0;
    for(int i=1,t,p;i<=N;i++) {
        cin >> t >> p;
        mx=max(mx, D[i]);
        D[i+t]=max(mx+p, D[i+t]);
    }
    cout << max(mx,D[N+1]);
    return 0;
}