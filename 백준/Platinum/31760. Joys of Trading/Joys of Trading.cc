#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
using al=array<ll,4>;

constexpr int sz=1<<17;
ll N, A[sz], U[sz], B[sz], W[sz];
ll T1[sz], T2[sz];

void sol(int tc) {
    cin >> N;
    vector<al> v;
    for(int i=1;i<=N;i++) {
        cin >> A[i] >> U[i] >> B[i] >> W[i];
        T1[0]+=A[i]*U[i], T2[N+1]+=B[i]*W[i];
        v.push_back({A[i],B[i],U[i],W[i]});
    }
    sort(all(v),[](al a, al b){
        return a[0]*b[1] < a[1]*b[0];
    });
    for(int i=0;i<N;i++) {
        auto [a,b,u,w] = v[i];
        A[i+1]=a, B[i+1]=b, U[i+1]=u, W[i+1]=w;
    }
    
    for(int i=1;i<=N;i++) T1[i]=T1[i-1]-A[i]*(U[i]+W[i]);
    for(int i=N;i;i--) T2[i]=T2[i+1]-B[i]*(U[i]+W[i]);

    double res = numeric_limits<double>::max();
    for(int i=1;i<=N;i++) {
        if(T1[i-1]<0 || T2[i+1]<0) continue;
        double time = 0, s = U[i] + W[i];
        if(A[i] == B[i]) {
            time = s*A[i];
        } else if(A[i] < B[i]) {
            s -= min<double>(T1[i-1], A[i]*s)/A[i];
            time = T1[i-1] + s * B[i];
        } else {
            s -= min<double>(T2[i+1], B[i]*s)/B[i];
            time = T2[i+1] + s * A[i];
        }
        res = min<double>(res, T1[0]-T1[i-1] + T2[N+1]-T2[i+1] + time);
    }
    cout << fixed << setprecision(12) << res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}