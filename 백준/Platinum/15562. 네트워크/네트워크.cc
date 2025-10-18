#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, M, IN[1010101], OUT[1010101];

void sol(int tc) {
    cin >> N >> M;
    for(int i=1;i<=M;i++) {
        int a,b; cin >> a >> b;
        if(a>b) swap(a,b);
        IN[b]++, OUT[a]++;
    }
    ll ans=0;
    for(int i=1;i<=N;i++) ans+=max(OUT[i]-IN[i], 0);
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}