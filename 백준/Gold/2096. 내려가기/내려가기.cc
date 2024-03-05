#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<ll> mx(3), mn(3);
    for(ll i=1,a,b,c;i<=n;i++) {
        cin >> a >> b >> c;
        mx={a+max(mx[0],mx[1]), b+max({mx[0],mx[1],mx[2]}), c+max(mx[1],mx[2])};
        mn={a+min(mn[0],mn[1]), b+min({mn[0],mn[1],mn[2]}), c+min(mn[1],mn[2])};
    }
    cout << *max_element(mx.begin(),mx.end()) << ' ' << *min_element(mn.begin(),mn.end());
    
    return 0;
}