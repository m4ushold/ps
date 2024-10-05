#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> A(n+1), S(n+1), T1(n+1), T2(n+2);
    for(int s=1; s<=n; s++)cin >> A[s], S[s] = S[s-1] + A[s];
    for(int s=n; s>=1; s--)T2[s] = T2[s+1] + abs(A[s]);
    for(int s=1; s<=n; s++)T1[s] = T1[s-1] + abs(A[s]);
    priority_queue<ll>pq;
    pq.push(0);
    ll ans = 0;
    for(int s=1; s<=n; s++) {
        ll now = 2 * S[s] + pq.top() + T2[s+1];
        ans = max(ans, 2 * S[s] + pq.top() + T2[s+1]);
        pq.push(T1[s] - 2 * S[s]);
    }
    cout << max(ans, T1[n]);
}