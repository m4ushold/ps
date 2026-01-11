#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, M, A[101010], B[101010], C[101010];

int add(int v, int c) {
    if(C[c] == 0) {
        C[c] = v;
        return 1;
    }
    if(C[c] < v) return 0;
    int u = C[c];
    C[c] = v;
    if(A[u] == c) return add(u,B[u]);
    return 0;
}

void sol(int tc) {
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i] >> B[i];

    int ans=0;
    vector<int> v;
    for(int i=N;i;i--) {
        ans += add(i, A[i]);
        v.push_back(ans);
    }
    reverse(all(v));
    for(int i:v) cout << i << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}