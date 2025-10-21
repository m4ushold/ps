#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

void sol(int tc) {
    ll n; cin >> n;
    if(n==1) {
        cout << 'N';
        return;
    }
    map<ll,int> m;
    for(ll i=2;i*i<=n;i++) {
        while(n%i==0 && n>1) m[i]++, n/=i;
    }
    if(n>1) m[n]++;
    if(m.size() > 2) {
        cout << 'N';
        return;
    }
    for(auto [i,j]:m) {
        if(~j&1) {
            cout << 'N';
            return;
        }
    }
    cout << 'Y';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}