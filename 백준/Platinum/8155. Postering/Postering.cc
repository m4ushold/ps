#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

void sol(int tc) {
    int n; cin >> n;
    vector<int> stk;
    stk.push_back(0);
    int ans=0;
    for(int i=0,a,b;i<n;i++) {
        cin >> a >> b;
        while(stk.back() > b) stk.pop_back();
        if(stk.back() < b) stk.push_back(b), ans++;
    }
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}