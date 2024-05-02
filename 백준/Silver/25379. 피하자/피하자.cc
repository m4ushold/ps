#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, e=0, o=0, ec=0, oc=0; cin >> n;
    for(int i=0,a;i<n;i++) {
        cin >> a;
        if(a&1) oc+=i-o, o++;
        else ec+=i-e, e++;
    }
    cout << min(ec,oc);
    return 0;
}