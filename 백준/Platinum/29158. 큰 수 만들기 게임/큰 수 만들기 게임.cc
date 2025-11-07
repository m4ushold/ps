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
    if(n==2) {
        cout << 3;
        return;
    }
    vector<ll> v;
    ll t=n;
    for(ll i=2;i*i<=n;i++) {
        while(t%i==0) v.push_back(i), t/=i;
        if(t==1) break;
    }
    if(t>1) v.push_back(t);
    ll x = 1, cnt=0, tt=0;
    while(x*2<n) x*=2, cnt++;
    if(x/2*3 < n) x=x/2*3, cnt--, tt++;
    string s;
    if(tt) s+='3';
    while(cnt--) s+='2';

    sort(all(v), [](ll a, ll b){
        string aa = to_string(a), bb = to_string(b);
        return aa+bb > bb+aa;
    });
    string ss;
    for(ll i:v) ss += to_string(i);

    reverse(all(s)), reverse(all(ss));
    // cout << s << ' ' << ss << endl;

    if(s.size() > ss.size()) swap(s, ss);
    vector<ll> res(ss.size());
    ll c=0;
    for(int i=0;i<min(s.size(),ss.size());i++) {
        res[i]=s[i]+ss[i]-'0'*2+c;
        c=res[i]/10;
        res[i]%=10;
    }
    for(int i=min(s.size(),ss.size());i<ss.size();i++) {
        res[i]=ss[i]+c-'0';
        c=res[i]/10;
        res[i]%=10;
    }
    if(c) res.push_back(c);
    reverse(all(res));
    
    for(ll i:res) cout << i;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}