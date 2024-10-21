#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    map<int,int> m;
    int n; cin >> n;
    for(int i=0,a,b;i<n;i++) {
        cin >> a >> b;
        if(a==1) {
            int mx=max({m[b],m[b+1],m[b+2],m[b+3]});
            for(int j=b;j<b+4;j++) m[j]=mx+1;
        } else if(a==2) {
            m[b]+=4;
        } else cout << m[b] << '\n';
    }
    
    return 0;
}