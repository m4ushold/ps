#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll s(ll a) { return a*(a+1)/2; }

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) {
        ll a,b; cin >> a >> b;
        cout << "Scenario #" << i << ":\n";
        if(a<0 && b<0) cout << -s(-a)+s(-b-1);
        else if(a<0) cout << s(b)-s(-a);
        else cout << s(b)-s(a-1);
        cout << "\n\n";
    }
    return 0;
} 