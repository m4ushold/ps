#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int N, M, A[101010], I[101010];
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i], I[A[i]]=i;
    ll a=0,b=0;
 
    int pos=0;
    for(int i=1;i<M;i++) {
        ll t = I[i] - pos;
        if(t < 0) t+=N;
        a+=t;
        pos = I[i];
    }
 
    pos=0;
    for(int i=N;i>=M;i--) {
        ll t = I[i] - pos;
        if(t < 0) t+=N;
        b+=t;
        pos = I[i];
    }
    
    if(a<b) cout << "CW";
    else cout << "CCW";
    return 0;
}