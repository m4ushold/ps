#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int f(int x) {
    for(int i=30;i>1;i--) {
        int t = round(pow(x,1./i));
        if(fabs(pow(t,i)-x) < 1e-9) return t;
    }
    return x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll ans=0;
    for(int i=1,x;i<=n;i++) {
        cin >> x;
        ans+=f(x);
    }
    cout << ans;
    return 0;
}