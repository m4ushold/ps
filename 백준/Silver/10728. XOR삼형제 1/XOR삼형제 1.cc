#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;

    while(t--) {
        int n, mx=0,s; cin >> n;
        for(int i=0;i<=__lg(n);i++) {
            int l=min(n,(1<<i)+(1<<i+1)-1)-(1<<i)+1;
            if(mx<l) mx=l, s=i;
        }
        cout << min(n,(1<<s)+(1<<s+1)-1)-(1<<s)+1 << '\n';
        for(int i=1<<s;i<=min(n,(1<<s)+(1<<s+1)-1);i++) cout << i << ' ';
        cout << "\n";
    }
    return 0;
}