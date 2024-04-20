#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1,a,b;i<=n;i++) {
        cin >> a >> b;
        cout << "Case " << i << ": " << a+b << '\n';
    }
    return 0;
}