#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int MOD=1e9+7;

struct Mat {
    int n;
    vector<vector<ll>> m;
    Mat(int n, int f=0) : n(n) { 
        m = vector(n, vector<ll>(n, 0)); 
        if(f) for(int i=0;i<n;i++) m[i][i]=1;
    }
    Mat(vector<vector<ll>> m) : m(m), n(m.size()) { }
    vector<ll>& operator[](int i) {return m[i];}

    Mat operator*(Mat& mm) {
        Mat res(n);
        for(int i=0; i<n; i++){
			for(int j=0; j<n; j++) {
				for(int k=0; k<n; k++) {
                    res[i][j] = (res[i][j] + m[i][k] * mm[k][j])%MOD;
                }
			}
		}
		return res;
    }
};

Mat pw(Mat m, ll n) {
    Mat res(m.n, 1);
    while(n) {
        if(n&1) res=res*m;
        m=m*m, n/=2;
    }
    return res;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin >> k >> n;
    k+=2;
    Mat a(k);
    for(int i=0;i<k;i++) for(int j=0;j<=i;j++) a.m[i][j]=1;
    auto v = pw(a, n-1).m[k-1];
    ll dap=0;
    for(ll i:v) dap=(dap+i)%MOD;
    cout << dap;
    return 0;
}