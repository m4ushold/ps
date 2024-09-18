#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    vector<int> r(100), rr(100);
    for(int i=0,a=0;i<n;i++) {
        int l, s; cin >> l >> s;
        for(int i=a;i<a+l;i++) r[i]=s;
        a+=l;
    }
    for(int i=0,a=0;i<m;i++) {
        int l, s; cin >> l >> s;
        for(int i=a;i<a+l;i++) rr[i]=s;
        a+=l;
    }
    int mx=0;
    for(int i=0;i<100;i++) mx=max(mx,rr[i]-r[i]);
    cout << mx;
    return 0;
}