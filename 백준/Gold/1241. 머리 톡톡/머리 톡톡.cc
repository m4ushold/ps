#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll C[1010101], A[1010101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i, C[i]++;
    for(int i=1;i<=1'000'000;i++) {
        for(int j=i;j<=1'000'000;j+=i) A[j]+=C[i];
    }
    for(int i:v) cout << A[i]-1 << '\n';

    return 0;
}