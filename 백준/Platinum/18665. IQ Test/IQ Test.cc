#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
set<ll> s;

void recur(ll n) {
    ll a= 1LL*sqrt(n)+1;
    if ((a-1)*(a-1) == n) a--;
    if (s.find(n) != s.end()) return;
    recur(a);
    recur(a*a-n);
    s.insert(n);
    cout << a << ' ' << a*a-n << '\n';
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    s.insert(0);
    s.insert(1);
    s.insert(2);
    recur(N);
    return 0;
}