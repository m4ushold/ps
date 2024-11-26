#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll MOD=1e9+7;
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,a,b,c,t;
    while(cin >> n >> MOD >> a >> b >> c >> t) {
        vector<ll> s(n);
        for(ll &i:s) cin >> i;

        Mat m(n);
        for(int i=0;i<n;i++) {
            m[i][i]=b;
            if(i==n-1) continue;
            m[i+1][i]=a, m[i][i+1]=c;
        }
        m = pw(m, t);

        for(auto vec:m.m) {
            ll dap=0;
            for(int i=0;i<n;i++) dap+=s[i]*vec[i]%MOD, dap%=MOD;
            cout << dap << ' ';
        }
        cout << '\n';
    }
}