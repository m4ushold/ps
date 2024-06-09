#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1000;

struct Mat {
    ll a,b,c,d;
    Mat operator*(const Mat& m) { 
        return {(a*m.a+b*m.c)%MOD, (a*m.b+b*m.d)%MOD, (c*m.a+d*m.c)%MOD, (c*m.b+d*m.d)%MOD};
    }
};

Mat pow(Mat m, ll n) {
    Mat ret={1,0,0,1};
    while(n) {
        if(n&1) ret=ret*m;
        m=m*m, n/=2;
    }
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) {
        ll n; cin >> n;
        Mat m=pow({6,-4,1,0}, n-1);
        ll dap=n==1 ? 5 : ((m.a*6+m.b*2-1)%MOD+MOD)%MOD;
        cout << "Case #" << i << ": " << setfill('0') << setw(3) << dap << endl;
    }
    return 0;
}