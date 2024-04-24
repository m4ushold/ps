#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    set<ll> s;
    for(ll i=0,a;i<n;i++) cin >> a, s.insert(a);
    vector<ll> v(s.begin(),s.end());
    ll mn=*min_element(v.begin(),v.end())/4;
    if(v.size() < 4) {
        cout << mn*(mn+1)/2;
        return 0;
    }
    s.clear();
    for(int i=0;i<4;i++) for(int j=i+1;j<4;j++) {
        ll diff=abs(v[j]-v[i]);
        for(ll k=1;k<sqrt(diff)+1;k++) if(diff%k==0) s.insert(k), s.insert(diff/k);
    }
    
    auto chk = [&](ll l) {
        if(l > mn) return 0;
        set<ll> ss;
        ss.clear();
        for(ll i:v) {
            ss.insert(i%l);
            if(ss.size()>3) {
                ss.clear();
                return 0;
            }
        }
        return 1;
    };

    ll res=0;    
    for(ll i:s) if(chk(i)) res+=i;
    cout << res;
    return 0;
}