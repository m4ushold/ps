#include <bits/stdc++.h>
using namespace std;
using ll=long long;

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
int N;
string S;

bool chk(int l)
{
    vector<pair<int,int>> v(N-l+1);
    for(int i=1;i<=N-l+1;i++) v[i-1]={H1.get(i,i+l-1), H2.get(i,i+l-1)};
    sort(v.begin(),v.end());
    for(int i=0;i<N-l+1;i++) if(v[i]==v[i+1]) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;
    H1.build(S), H2.build(S);

    int s=0,e=N;
    while(s<e) {
        int m=(s+e+1)/2;
        if(chk(m)) s=m;
        else e=m-1;
    }
    cout << s;
    return 0;
}