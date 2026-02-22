#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

void sol(int tc) {
    int n,m; cin >> n >> m;
    vector<int> v(m+1);
    v[1]=v[2]=1;
    for(int i=3;i<=m;i++) v[i]=(v[i-1]+v[i-2])%10;
    for(int i=n;i<=m;i++) cout << v[i];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}