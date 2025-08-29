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
    ll get(int s, int e) { return ((H[e]-H[s-1]*B[e-s+1])%M+M)%M; }
};

Hashing<917, 998244353> H;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    H.build(s);
    int l=0, r=s.size()-1, cnt=0;
    while(l<=r) {
        int f=0;
        for(int len=0;l+len<r-len;len++) {
            int ll=l+len, rr=r-len;
            if(H.get(l+1,ll+1) == H.get(rr+1,r+1)) {
                l=ll+1, r=rr-1;
                cnt+=2;
                f=1;
                break;
            }
        }
        if(!f) {cnt++; break;}
    }
    cout << cnt;
    return 0;
}