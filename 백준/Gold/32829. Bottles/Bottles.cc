#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int A[303], B[303];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    vector<tuple<ll,ll,ll>> v;
    for(int i=0;i<n;i++) {
        ll s=0;
        for(int j=1,a;j<=m;j++) {
            cin >> a;
            v.push_back({s,j,1});
            s+=a;
            v.push_back({s,j,-1});
        }
    }
    sort(v.begin(),v.end());
    ll p=0, pp;
    for(auto [t,i,a]:v) {
        A[i]+=a;
        B[i]=max(B[i], A[i]);
        p=t, pp=i;
    }

    for(int i=1;i<=m;i++) cout << B[i] << ' ';
    return 0;
}