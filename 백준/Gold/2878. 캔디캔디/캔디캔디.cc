#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll M, N, A[101010];

bool chk(ll m) {
    ll candy=M;
    for(int i=1;i<=N;i++) {
        candy -= max((ll)0,A[i]-m);
        if(candy < 0) return 0;
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> M >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    ll l=0,r=2e9;
    while(l<r) {
        ll m=l+r>>1;
        if(chk(m)) r=m;
        else l=m+1;
    }
    
    ll candy=M;
    priority_queue<ll> pq;
    for(int i=1;i<=N;i++) {
        ll t = max((ll)0,A[i]-r);
        candy -= t;
        pq.push(A[i] - t);
    }
    while(candy--) {
        pq.push(pq.top()-1); pq.pop();
    }

    unsigned long long ans=0;
    while(pq.size()) {
        unsigned long long t=pq.top(); pq.pop();
        ans+=t*t;
    }
    cout << ans;
    return 0;
}