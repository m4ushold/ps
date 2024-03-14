#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,k,m=0,i=0; cin >> n >> k;
    while(__popcount(n)>k) {
        if((n>>i)&1) n+=1LL<<i, m+=1LL<<i;
        i++;
    }
    cout << m;
    return 0;
}