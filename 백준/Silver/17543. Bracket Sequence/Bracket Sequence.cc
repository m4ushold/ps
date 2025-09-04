#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int mod = 1e9+7;

void sol(int tc) {
    int n; cin >> n;
    vector<ll> v(n);
    for(ll &i:v) {
        string s; cin >> s;
        if(s=="(") i=-1;
        else if(s==")") i=-2;
        else i=stoll(s);
    }
    vector<ll> stk;
    int cnt=0;
    for(ll i:v) {
        if(i == -1) cnt++;
        if(i == -2) {
            int op = cnt & 1;
            ll res=op?1:0;
            while(stk.back() != -1) {
                if(op) res=res*stk.back()%mod;
                else res=(res+stk.back())%mod;
                stk.pop_back();
            }
            stk.pop_back();
            stk.push_back(res);
            cnt--;
        } else stk.push_back(i);
    }

    ll ans=0;
    for(ll i:stk) ans=(ans+i)%mod;
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}