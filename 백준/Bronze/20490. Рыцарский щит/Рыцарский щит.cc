#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    int a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;
    cout << a+b+c+d+e+f-2*min(max({a,b,c}),max({d,e,f}));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}