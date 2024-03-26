#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n,m,a; cin >> n >> m;
        for(int i=0;i<2*m;i++) cin >> a;
        cout << n-1 << '\n';
    }
    return 0;
}