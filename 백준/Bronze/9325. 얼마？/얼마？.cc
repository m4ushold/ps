#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int s, n, a, b; cin >> s >> n;
        while(n--) cin >> a >> b, s+=a*b;
        cout << s << '\n';
    }
    return 0;
}