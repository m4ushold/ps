#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template<ll P, ll M>
struct Hashing {
    vector<ll> B, H;
    void build(const string& s) {
        B.resize(27), H.resize(s.size()+1);
        B[0]=1;
        for(int i=1;i<27;i++) B[i]=B[i-1]*P%M;
        for(int i=1;i<=s.size();i++) H[i]=(H[i-1]+B[s[i-1]-'a'])%M;
    }
    ll get(int s, int e) { return ((H[e]-H[s-1])%M+M)%M; }
};

Hashing<100013, 998244353> h1a, h1b;
Hashing<100003, 1000000103> h2a, h2b;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b; cin >> a >> b;
    h1a.build(a), h2a.build(a), h1b.build(b), h2b.build(b);

    for(int l=min(a.size(),b.size());l;l--) {
        set<pair<ll,ll>> s;
        for(int i=1;i+l-1<=a.size();i++) s.insert({h1a.get(i,i+l-1), h2a.get(i,i+l-1)});
        for(int i=1;i+l-1<=b.size();i++) {
            if(s.count(make_pair(h1b.get(i,i+l-1), h2b.get(i,i+l-1)))) {
                cout << l;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}