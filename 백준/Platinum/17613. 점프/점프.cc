#include <bits/stdc++.h>
using namespace std;

int DP[32]={0,1,2};

int f(int n) {
    int l=__lg(n+1), m=(1<<l)-1;
    if(m==n) return DP[l];
    return max(DP[l],l+f(n-m));
}

int dnc(int s, int e) {
    int l=__lg(e+1), m=(1<<l)-1;
    if(s==m) return l+f(e-s);
    else if(s<=m && m<=e) return max(dnc(s,m-1),dnc(m,e));
    return l+dnc(s-m,e-m);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=3;i<32;i++) DP[i]=DP[i-1]+i-1;

    int t; cin >> t;
    while(t--) {
        int s,e; cin >> s >> e;
        cout << dnc(s,e) << '\n';
    }
    return 0;
}