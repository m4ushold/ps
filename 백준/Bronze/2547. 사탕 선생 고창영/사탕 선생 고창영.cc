#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        ll n,a,s=0; cin >> n;
        for(int i=0;i<n;i++) cin >> a, s=(s+a)%n;
        cout << (s==0?"YES\n":"NO\n");
    }
    return 0;
}