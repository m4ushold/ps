#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template<ll P, ll M>
struct Hashing {
    vector<ll> B, H;
    void build(const string& s) {
        B.resize(s.size()+1), H.resize(s.size()+1);
        B[0]=1;
        for(int i=1;i<=s.size();i++) H[i]=(H[i-1]*P+s[i-1])%M, B[i]=B[i-1]*P%M;
    }
    // 1-base
    ll get(int s, int e) { return ((H[e]-H[s-1]*B[e-s+1])%M+M)%M; }
};

int N, K;
Hashing<100003, 1000000103> H;

bool f(int len) {
    vector<ll> v;
    for(int i=1;i+len-1<=N;i++) {
        v.push_back(H.get(i,i+len-1));
    }
    sort(v.begin(),v.end());
    if(v.size()==1 || v[0]!=v[1] || v.back()!=v[v.size()-2]) return 1;
    for(int i=1;i<v.size()-1;i++) {
        if(v[i]!=v[i-1] && v[i]!=v[i+1]) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    N=s.size();
    H.build(s);

    int l=1,r=N;
    while(l<r) {
        int m=(l+r)/2;
        if(f(m)) r=m;
        else l=m+1;
    }

    map<ll,ll> m;
    for(int i=1;i+r-1<=N;i++) {
        m[H.get(i,i+r-1)]++;
    }
    for(int i=1;i+r-1<=N;i++) {
        if(m[H.get(i,i+r-1)]==1) {
            cout << s.substr(i-1,r);
            return 0;
        }
    }
    
    cout << s;
    return 0;
}