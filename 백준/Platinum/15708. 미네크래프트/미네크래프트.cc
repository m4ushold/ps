#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, P, T, A[101010];

void sol(int tc) {
    cin >> N >> T >> P;
    priority_queue<ll> pq;
    ll res=0, sum=0;
    for(int i=1;i<=N;i++) {
        cin >> A[i];
        pq.push(A[i]);
        sum+=A[i];
        if(i>1) sum+=P;
        while(sum > T && pq.size()) sum-=pq.top(), pq.pop();
        if(sum <= T) res=max<int>(res,pq.size());
    }
    cout << res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}