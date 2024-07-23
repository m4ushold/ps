#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int A[20202];

void sol(int id) {
    memset(A, 0, sizeof(A));
    ll n; cin >> n;
    queue<pair<ll,string>> q;
    q.push({1,"1"});
    while(q.size()) {
        auto [i,s]=q.front(); q.pop();
        if(A[i]) continue; A[i]=1;
        if(i==0) { cout << s << '\n'; return; }
        if(s.size()>100) return;
        if(!A[i*10%n]) q.push({i*10%n, s+"0"});
        if(!A[(i*10+1)%n]) q.push({(i*10+1)%n, s+"1"});
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}