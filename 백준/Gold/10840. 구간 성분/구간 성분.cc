#include <bits/stdc++.h>
using namespace std;
using ll=long long;

template<ll M>
struct Hashing {
    vector<ll> B, H;
    void build(const string& s) {
        B.resize(27), H.resize(s.size()+1);
        B[0]=1;
        for(int i=1;i<27;i++) B[i]=B[i-1]*27%M;
        for(int i=1;i<=s.size();i++) H[i]=(H[i-1]+B[s[i-1]-'a'])%M;
    }
    ll get(int s, int e) { return ((H[e]-H[s-1])%M+M)%M; }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b; cin >> a >> b;
    if(a.length() > b.length()) swap(a,b);

    Hashing<998244353> h1a, h1b;
    Hashing<1000000103> h2a, h2b;
    h1a.build(a), h2a.build(a), h1b.build(b), h2b.build(b);

    int la=a.size(), lb=b.size();
    for(int i=la;i>=1;i--) { // length
        set<int> s1, s2;
        for(int j=1;i+j-1<=la;j++) s1.insert(h1a.get(j,i+j-1)), s2.insert(h2a.get(j,i+j-1));
        for(int j=1;i+j-1<=lb;j++) {
            if(s1.count(h1b.get(j,j+i-1)) && s2.count(h2b.get(j,j+i-1))) {
                cout << i;
                return 0;
            }
        }
    }
    cout << 0;    
    return 0;
}