#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll a,b,t=0; cin >> a >> b;
    for(ll i=sqrt(a+b)-10;i<=sqrt(a+b)+10;i++) if(i*i==a+b) {t=abs(i); break;}
    if(a==2 || b==2 || (a+b && !t)) {cout << -1; return 0;}
    ll cnt=0;
    for(ll i=t;i>0;i--) {
        if(a>=2*i-1) a-=2*i-1, cnt++;
    }
    cout << cnt+a;
    return 0;
}