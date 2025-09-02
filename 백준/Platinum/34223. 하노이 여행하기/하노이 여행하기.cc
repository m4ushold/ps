#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lca(ll a, ll b) {return a/gcd(a,b)*b;}
 
void sol(int tc) {
    ll n; cin >> n;
    if(n==6) {
        cout << "2 3 1 5 4 5\n1 6\n";
        return;
    }
    ll mx=0, a;
    for(int i=0;i<=n;i++) {
        ll l = i?lca(i,n-i):n;
        if(l>mx) mx=l, a=i;
    }
    if(!a) {
        for(int i=1;i<n;i++) cout << i+1 << ' ';
        cout << 1 << '\n' << 1 << ' ' << n << '\n';
        return;
    }
 
    for(int i=1;i<a;i++) cout << i+1 << ' ';
    cout << 1 << ' ';
    for(int i=a+1;i<n;i++) cout << i+1 << ' ';
    cout << a+1 << ' ';
    cout << '\n';
    cout << 1 << ' ' << n << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}