#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, G[202020], R[202020], B[202020], NB[202020];
map<int,int> M;

void ns(int mx) {
    B[0]=1;
    for(auto [x,cnt]:M) {
        for(int i=0;i<x;i++) {
            int c=0;
            for(int j=0;j*x+i<=mx;j++) {
                c+=B[j*x+i];
                if(j>cnt) c-=B[(j-cnt-1)*x+i];
                if(c) NB[j*x+i]=1;
            }
        }
        for(int i=0;i<=mx;i++) B[i]|=NB[i], NB[i]=0;
    }
}

void sol(int tc) {
    cin >> N;
    if(N==1) {cout << 'N';return;}
    
    ll g = 0, s = 0, f=0;
    for(int i=1;i<=N;i++) cin >> G[i] >> R[i], g=gcd<ll>(g, R[i]), s+=G[i], M[G[i]]++, f|=G[i]==0;
    ns(s);
    if(!f) B[0]=0;
    for(int i=0;i<s;i++) if(B[i] && i*2%g == s%g) {
        cout << 'Y';
        return;
    }
    cout << 'N';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}