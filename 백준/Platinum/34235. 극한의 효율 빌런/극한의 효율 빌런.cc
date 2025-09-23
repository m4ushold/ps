#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, K, V[1010], C[1010], D[5050];

bool chk(int x) {
    for(int i=0;i<5050;i++) D[i]=LLONG_MAX/4;
    D[0]=0;
    for(int i=1;i<=N;i++) {
        for(int j=5000;j>=0;j--) {
            if(j+V[i]<5050) D[j+V[i]]=min(D[j+V[i]], D[j]+C[i]-x);
        }
    }
    ll res=LLONG_MAX/4;
    for(int i=K;i<5050;i++) res=min(res,D[i]);
    return res>=0;
}

void sol(int tc) {
    cin >> N >> K;
    for(int i=1;i<=N;i++) cin >> V[i] >> C[i];
    int l=0, r=1e9;
    while(l<r) {
        int m=l+r+1>>1;
        if(chk(m)) l=m;
        else r=m-1;
    }
    cout << l;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}