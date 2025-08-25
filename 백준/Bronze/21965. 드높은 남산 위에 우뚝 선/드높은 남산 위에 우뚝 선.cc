#include <bits/stdc++.h>
using namespace std;

void sol(int tc) {
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    int s=0,e=n-1;
    while(v[s]<v[s+1] && s+1<n) s++;
    while(v[e-1]>v[e] && e>0) e--;
    cout << (s==e?"YES":"NO");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}