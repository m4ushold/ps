#include <bits/stdc++.h>
using namespace std;
using ll=long long;

bitset<100> A[10101];

void sol(int tc) {
    int n,r; cin >> n >> r;
    for(int i=0;i<r;i++) {
        for(int j=1;j<=2*n;j++) {
            int x; cin >> x;
            A[j][i] = x>n ? 1 : 0;
        }
    }
    unordered_map<bitset<100>,int> m;
    for(int i=1;i<=2*n;i++) {
        m[A[i]]++;
    }
    for(auto [i,j]:m) {
        bitset<100> t;
        for(int k=0;k<r;k++) t[k]=i[k]^1;
        if(m[t] != j) {
            cout << "impossible";
            return;
        }
    }
    cout << "possible";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}