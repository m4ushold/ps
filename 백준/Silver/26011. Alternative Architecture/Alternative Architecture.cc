#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll a,b; cin >> a >> b;
    if(a>b) swap(a,b);
    a--, b--;
    ll dap=0;
    for(ll i=0;i<a;i++) {
        ll c=i, d=sqrt(a*a-c*c), e=b*c/a, f=b*d/a;
        if(c*c+d*d==a*a && e*e+f*f==b*b) dap+=a==b?1:2;
    }
    cout << dap;
    return 0;
}