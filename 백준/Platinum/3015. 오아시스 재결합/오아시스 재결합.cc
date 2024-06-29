#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    stack<pair<ll,ll>> s;
    ll dap=0, t;
    for(ll i:v) {
        t=1;
        while(s.size() && s.top().first <= i) {
            dap+=s.top().second;
            if(s.top().first==i) t=s.top().second+1;
            s.pop();
        }

        if(s.size()) dap++;
        s.push({i,t});
    }
    cout << dap;

    return 0;
}