#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll P[55]={1}, L[55]={1};

ll f(ll n, ll x) {
    if(n==0) return 1;

    if(x<=1) return 0;
    else if(L[n]==x) return P[n];
    else if((L[n-1]+2==x)) return P[n-1]+1;
    else if(1+L[n-1]>=x) return f(n-1,x-1);
    else return P[n-1]+1+f(n-1,x-2-L[n-1]);
}

int main() {
    ll n,x; cin >> n >> x;
    for(int i=1;i<55;i++) P[i]=P[i-1]*2+1, L[i]=L[i-1]*2+3;
    cout << f(n, x);
    return 0;
} 