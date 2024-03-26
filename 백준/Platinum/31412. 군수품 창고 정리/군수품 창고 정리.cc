#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M;
vector<ll> A, B;

bool chk(ll m) {
    sort(B.begin(),B.end());
    do {
        ll b=0;
        for(int i=0;i<M;i++) {
            int idx=upper_bound(A.begin(), A.end(), A[b]+B[i]*m)-A.begin();
            if(idx==N+1) return 1;
            b=idx-1;
        }
    } while(next_permutation(B.begin(),B.end()));
    return 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    A.resize(N+1);
    for(int i=1;i<=N;i++) cin >> A[i], A[i]+=A[i-1];
    for(int i=0,a;i<M;i++) cin >> a, B.push_back(a);

    ll s=0, e=A[N];
    while(s+1<e) {
        ll m=s+e>>1;
        if(chk(m)) e=m;
        else s=m;
    }
    cout << e;
    
    return 0;
}