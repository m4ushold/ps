#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int id) {
    ll n; cin >> n;
    vector<int> t;
    for(int i=1;i<50;i++) t.push_back(i*(i+1)/2);
    for(int i:t) for(int j:t) for(int k:t) if(i+j+k==n) {
        cout << "1\n";
        return;
    }
    cout << "0\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}