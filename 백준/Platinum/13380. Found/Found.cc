#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, T;
vector<int> G[101], A[101];

int node(int u, int v) {
    return u*N + v;
}

constexpr int MOD=9973;

struct Mat {
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

void sol() {
    cin >> N >> M >> T;
    for(int i=0;i<101;i++) A[i].clear(), G[i].clear();

    for(int i=0,u,v;i<M;i++) {
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v), G[v].push_back(u);
    }

    Mat m(N*N);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(i^j) {
        int s = node(i,j);
        for(auto ii:G[i]) for(int jj:G[j]) {
            if(ii^jj) m[s][node(ii,jj)]=1;
            else A[ii].push_back(s);
        }
    }

    auto x = pw(m, T-1);
    ll ans=0, s=node(0,N-1);
    for(int i=0;i<N;i++) {
        for(int j:A[i]) ans = (ans + x[s][j]) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}