#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, A[101010], D[101010];

void sol(int tc) {
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> A[i];
        D[i]=min(D[i-1]+1,A[i]);
    }
    cout << *max_element(D, D+101010);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}