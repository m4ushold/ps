#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

vector<int> manacher(vector<pll> &inp){
    int n = inp.size() * 2 + 1;
    vector<int> ret(n);
    vector<pll> s;
    s.push_back({-1,-1});
    for(auto i:inp) s.push_back(i), s.push_back({-1,-1});
    for(int i=0, p=-1, r=-1; i<n; i++){
        ret[i] = i <= r ? min(r-i, ret[2*p-i]) : 0;
        while(i-ret[i]-1 >= 0 && i+ret[i]+1 < n && s[i-ret[i]-1] == s[i+ret[i]+1])
        ret[i]++;
        if(i+ret[i] > r) r = i+ret[i], p = i;
    }
    return ret;
}

template<ll P, ll M> struct Hashing {
    vector<ll> B, H;
    void build(const string& s) {
        B.resize(s.size()+1), H.resize(s.size()+1);
        B[0]=1;
        for(int i=1;i<=s.size();i++) H[i]=(H[i-1]*P+s[i-1])%M, B[i]=B[i-1]*P%M;
    }
    ll get(int s, int e) { return ((H[e]-H[s-1]*B[e-s+1])%M+M)%M; }
};

Hashing<917, 998244353> H1;
Hashing<100003, 1000000103> H2;

void sol(int tc) {
    int n; cin >> n;
    string s; cin >> s;
    H1.build(s);
    H2.build(s);
    for(int i=1;i<=n;i++) {
        ll ans=0;
        for(int k=0;k<i;k++) {
            vector<pll> v;
            for(int j=1+k;j+i-1<=n;j+=i) {
                v.push_back({H1.get(j,j+i-1),H2.get(j,j+i-1)});
            }
            auto a = manacher(v);
            for(int j:a) ans+=(j+1)/2;
        }
        cout << ans << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}