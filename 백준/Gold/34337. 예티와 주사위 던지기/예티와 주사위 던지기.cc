#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll A[11], S[10101], C[10101], X[11], cnt;

int mx() {
    vector<int> s(7);
    for(int i=0;i<5;i++) s[X[i]]+=X[i];
    for(int i=1;i<=6;i++) if(i*5 == s[i]) return 50;
    return *max_element(s.begin(),s.end());
}

void f(int x=0) {
    if(x==5) {
        for(int i=0;i<1<<6;i++) {
            int f=1;
            for(int j=0;j<6;j++) if(i&(1<<j)) f&=A[j]==X[j];
            if(!f) continue;
            S[i]+=mx(), C[i]++;
        }
        return;
    }
    for(int i=1;i<=6;i++) {
        X[x]=i;
        f(x+1);
    }
}

void sol(int tc) {
    for(int i=0;i<5;i++) cin >> A[i];
    reverse(A, A+5);
    f();
    ll t = 6*6*6*6*6, mx=0;
    for(int i=0;i<1<<6;i++) mx=max(mx,S[i]*t/C[i]);
    cout << mx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}