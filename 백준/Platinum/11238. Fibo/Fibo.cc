#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9+7;

struct Mat
{
    ll a,b,c,d;
    Mat operator*(const Mat& m) { 
        return {(a*m.a+b*m.c)%MOD, (a*m.b+b*m.d)%MOD, 
        (c*m.a+d*m.c)%MOD, (c*m.b+d*m.d)%MOD};
    }
};

Mat pow(Mat &m, ll n)
{
    Mat e={1,0,0,1};
    while(n) {
        if(n&1) e=e*m;
        m=m*m, n/=2;
    }
    return e;
}

ll fibo(ll n)
{
    Mat m={1,1,1,0};
    return pow(m,n).b;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        ll n,m; cin >> n >> m;
        cout << fibo(gcd(n,m)) << '\n';
    }
    return 0;
}