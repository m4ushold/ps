#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9+7;
ll N, A[55], B[55], MN=LLONG_MAX/2, I;
map<ll,ll> M[22];
vector<pair<ll,ll>> V[22];

void f(int l, int r) {
    for(int i=0;i<1LL<<(r-l+1);i++) {
        ll a=0, b=0;
        for(int j=r-l;j>=0;j--) {
            if(i&(1LL<<j)) a+=A[r-j];
            else b+=B[r-j];
        }

        if(!l) M[__popcount(i)][a-b]=max(M[__popcount(i)][a-b],(ll)i);
        else {
            int t = N/2-__popcount(i);
            pair<ll,ll> aa={b-a,LLONG_MAX};
            int idx = upper_bound(V[t].begin(),V[t].end(), aa)-V[t].begin();
            if(idx) idx--;
            for(int j=0;j<2;j++) if(idx+j < V[t].size()) {
                ll tmp = abs(V[t][idx+j].first+a-b);
                if(MN > tmp) {
                    MN = tmp;
                    I = (V[t][idx+j].second << (r-l+1)) | i;
                } else if(MN == tmp) {
                    I = max(I, (V[t][idx+j].second << (r-l+1)) | i);
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++) cin >> B[i];

    f(0,N/2-1);
    for(int i=0;i<=N/2;i++) {
        for(auto j:M[i]) V[i].push_back(j);
    }
    f(N/2,N-1);
    for(int i=N-1;i>=0;i--) cout << (I&(1LL<<i) ? 1 : 2) << ' ';
    return 0;
}