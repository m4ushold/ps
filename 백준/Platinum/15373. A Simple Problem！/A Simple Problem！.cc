#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 202020;
int S[sz], R[sz]={1,1};

void sol(int tc) {
    for(int i=2;i<sz;i++) if(!S[i]) for(int j=i;j<sz;j+=i) S[j]=i;

    int t,mx=0; cin >> t;
    vector<int> q(t);
    for(int &i:q) cin >> i, mx=max(mx,i);

    for(int i=2;i<=mx;i++) {
        int k=R[i-1], n=i;
        while(n>1) {
            int p=S[n], e=0;
            for(int j=i;j;) j/=p, e+=j;
            e<<=1;
            for(int j=k;j;) j/=p, e-=j;
            while(e>0) {
                for(int j=++k;j%p==0;j/=p) e--;
            }

            while(n%p==0) n/=p;
        }
        R[i]=k;
    }

    for(int i:q) cout << R[i] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}