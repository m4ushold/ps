#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

void sol(int tc) {
    int n,m,s,d; cin >> n >> m >> s >> d;
    vector<int> v(s), a(s);
    vector<pll> b;
    for(int i=0;i<s;i++) {
        cin >> v[i];
        b.push_back({v[i],i});
    }
    sort(b.begin(),b.end());
    for(auto [x,i]:b) {
        n-=d-x;
        a[i]=d-x;
        if(n<=0) {
            a[i]+=n, n=0;
            break;
        }
    }
    ll sum=0;
    for(int i=0;i<s;i++) {
        if(a[i]) continue;
        sum+=v[i];
    }
    if(sum < m) {
        cout << "impossible";
        return;
    }
    for(int i:a) cout << i <<" ";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}