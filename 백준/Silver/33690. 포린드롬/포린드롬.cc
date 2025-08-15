#include <bits/stdc++.h>
using namespace std;
using ll=long long;

bool f(string s) {
    s.pop_back();
    for(int i=0;i<s.size()/2;i++) if(s[i]!=s[s.size()-1-i]) return 0;
    return 1;
}

void sol(int tc) {
    ll n; cin >> n;
    int ans=0;
    for(int i=1;i<=min<int>(n,1e5);i++) {
        string a=to_string(i),b=a,t=a;
        reverse(t.begin(),t.end());
        a+=t, b+=t.substr(1);
        if(stoll(a) <= n && f(a)) ans++;
        if(stoll(b) <= n && f(b)) ans++;
    }
    cout << ans+1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}