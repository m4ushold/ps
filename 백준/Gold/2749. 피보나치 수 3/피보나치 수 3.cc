#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e6;

struct Mat2d
{
    ll a,b,c,d;
    Mat2d operator*(const Mat2d& m) { 
        return {(a*m.a+b*m.c)%MOD, (a*m.b+b*m.d)%MOD, (c*m.a+d*m.c)%MOD, (c*m.b+d*m.d)%MOD};
    }
};

ll fibo(ll n)
{
    Mat2d m={1,1,1,0}, i={1,0,1,0};
    while(n) {
        if(n&1) i=i*m;
        m=m*m, n/=2;
    }
    return i.b;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    cout << fibo(n);
    return 0;
}