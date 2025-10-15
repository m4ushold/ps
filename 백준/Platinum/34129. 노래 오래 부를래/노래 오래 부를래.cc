#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

bitset<100'000> D[1001];

void sol(int tc) {
    int n,k; cin >> n >> k;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        v.push_back({x,i});
    }
    sort(all(v));
    vector<int> ans;
    int mx = v.back().first, cnt = 1, b = mx;
    ans.push_back(v.back().second);
    v.pop_back();
    D[0][0]=1, n--;
    for(int i=0;i<n;i++) D[i+1] = D[i] | (D[i]<<v[i].first);
    for(int i=k-1;i>=0;i--) if(D[n][i]) {
        mx += i, b = i;
        break;
    }
    for(int i=n;i>0;i--) {
        if(D[i-1][b] ^ D[i][b]) ans.push_back(v[i-1].second), b-=v[i-1].first;
    }
    cout << ans.size() << ' ' << mx << endl;
    reverse(all(ans));
    for(int i:ans) cout << i+1 << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}