#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int A[1010101];

void sol(int tc) {
    int n; cin >> n;
    for(int i=0,a,b,c;i<n;i++) {
        cin >> a >> b >> c;
        if(max({++A[a], ++A[b], ++A[c]}) > 1) {
            cout << 1;
            return;
        }
    }
    cout << 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}