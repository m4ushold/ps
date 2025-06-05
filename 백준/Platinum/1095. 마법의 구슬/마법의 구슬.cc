#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<17;
int S, F, M, A[sz], C[sz];

bool chk(int x) {
    map<int,int> m;
    while(x) {
        if(x == 1) break;
        else if(A[x] == 0) {m[x]++; break;}
        m[A[x]]++;
        x/=A[x];
    }

    for(auto [p,c]:m) {
        if(C[p] < c) return 0;
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=2;i<sz;i++) if(A[i] == 0) for(int j=2*i;j<sz;j+=i) A[j]=i;
    cin >> S >> F >> M;
    for(int i=2;i<sz;i++) if(A[i] == 0) {
        for(ll j=i;j<=S+F;j*=i) {
            C[i] += (S+F)/j - S/j - F/j;
        }
    }

    for(int i=M;i;i--) {
        if(chk(i)) {
            return cout << i, 0;
        }
    }
    return 0;
}