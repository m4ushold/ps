#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll d,a,b,p,q; cin >> d >> a >> b, p=max(a,b), q=min(a,b);
    ll mn=1e9;
    for(int i=0;i<=min(d/p,q);i++) mn=min(mn,(q-(d-p*i)%q)%q);
    mn=min(mn,(p-(d%p))%p);
    cout << d+mn;
    return 0;
}