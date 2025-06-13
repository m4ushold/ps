#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, S, E, T, A[11][11], G[55][55];

int node(int i, int k) {
    return i*5+k;
}

struct Mat {
    const static int MOD=1'000'003;
    int n;
    vector<vector<ll>> m;
    Mat(int n, int f=0) : n(n) { 
        m = vector<vector<ll>>(n, vector<ll>(n, 0)); 
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
    cin >> N >> S >> E >> T;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
        char c; cin >> c;
        A[i][j] = c-48;
    }

    for(int i=0;i<N;i++) for(int k=0;k<4;k++) {
        G[node(i,k)][node(i,k+1)]=1;
    }

    for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(A[i][j] && (i^j)) {
        G[node(i,A[i][j]-1)][node(j,0)]=1;
    }

    Mat m(N*5);
    for(int i=0;i<N*5;i++) for(int j=0;j<N*5;j++) {
        m[i][j] = G[i][j];
    }

    cout << pw(m, T)[node(S-1, 0)][node(E-1, 0)];
    return 0;
}