#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<string> v(n);
    map<char,ll> m;
    for(auto &s:v) cin >> s;

    for(auto s:v) {
        reverse(s.begin(),s.end());
        for(ll i=0,b=1;i<s.size();i++,b*=10) m[s[i]] += b;
    }

    vector<pair<ll,char>> vec;
    for(auto [c,cnt]:m) vec.emplace_back(cnt,c);
    sort(vec.begin(),vec.end(),greater<>());

    for(int i=0;i<vec.size();i++) {
        m[vec[i].second] = 9-i;
    }

    for(auto &s:v) for(char &c:s) c=m[c]+48;

    ll dap=0;
    for(auto &s:v) dap+=stoll(s);
    cout << dap;
    return 0;
}