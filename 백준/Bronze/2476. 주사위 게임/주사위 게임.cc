#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int mx=0;
    for(int i=0,a,b,c;i<n;i++) {
        cin >> a >> b >> c;
        if(a>b) swap(a,b);
        if(b>c) swap(b,c);
        if(a>b) swap(a,b);
        if(a==c) mx=max(mx,10'000+a*1000);
        else if(a==b) mx=max(mx,1000+a*100);
        else if(b==c) mx=max(mx,1000+b*100);
        else mx=max(mx,c*100);
    }
    cout << mx;

    return 0;
}