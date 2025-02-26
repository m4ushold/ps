#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll a,b; cin >> a >> b;
    ll n; cin >> n;
    vector<pair<ll,ll>> aa, bb;
    for(ll i=1,l,r;i<=n;i++) {
        cin >> l >> r;
        aa.push_back({l,i});
        bb.push_back({r,i});
    }
    sort(aa.begin(),aa.end());

    ll g = a-b+1;

    if(a < b) {
        cout << "-1 -1\n";
    } else {
        ll dap = INT_MAX, lla=1, rra=1;
        for(auto [r,i]:bb) {
            pair<ll,ll> t={g-r,0};
            ll j = lower_bound(aa.begin(),aa.end(), t) - aa.begin();
            while(j<aa.size() && aa[j].second == i) j++;
            if(j>=aa.size()) continue;
            
            if(dap == INT_MAX || dap > aa[j].first + r) {
                dap = aa[j].first + r, lla = aa[j].second, rra = i;
            }

            
        }
        for(auto [r,i]:bb) {
            if(g<=r && dap > r) dap = r, lla=-1, rra=i;
        }
        for(auto [l,i]:aa) {
            if(g<=l && dap > l) dap = l, lla=i, rra=-1;
        }

        if(dap == INT_MAX) cout << "No";
        else cout << lla << ' ' << rra;
    }
    return 0;
}