#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    ll s=0;
    for(int i=0,t;i<n;i++) {
        cin >> t;
        s+=pow(t/10, t%10);
    }
    cout << s;
    return 0;
}