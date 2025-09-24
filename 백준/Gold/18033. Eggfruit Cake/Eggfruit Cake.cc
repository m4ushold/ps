#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

void sol(int tc) {
    string s; cin >> s;
    int k,n=s.size(); cin >> k;
    s+=s;

    vector<int> v;
    for(int i=0;i<n*2;i++) {
        if(s[i] == 'E') v.push_back(i);
    }
    if(v.empty()) {
        cout << "0";
        return;
    }

    ll ans=0;
    for(int i=0;i<n;i++) {
        int j = *lower_bound(v.begin(),v.end(),i);
        ans += max(i+k-j,0);
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