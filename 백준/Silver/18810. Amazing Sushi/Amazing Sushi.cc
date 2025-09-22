#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

void sol(int tc) {
    int n; cin >> n;
    int a,b,c,d; cin >> a >> b >> c >> d;
    int r=0;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        a-=x/2, b-=x/2, c-=x/2, d-=x/2;
        r+=x&1;
    }
    
    if(a>0) r-=a, b-=a, a=0;
    if(c>0) r-=c, d-=c, c=0;
    if(r<0) {
        cout << "No";
        return;
    }
    // cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << r << endl;
    if(b < 0 || d < 0) cout << "No";
    else if(b+d >= r) cout << "Yes";
    else cout << "No";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}