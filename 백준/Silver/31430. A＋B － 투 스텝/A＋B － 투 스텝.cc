#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if(n==1) {
        ll a,b; cin >> a >> b;
        vector<int> v;
        ll c = a+b;
        while(c) v.push_back(c%26), c/=26;
        while(v.size() < 13) v.push_back(0);
        while(v.size()) cout << (char)(v.back() + 'a'), v.pop_back();
    } else {
        string s; cin >> s;
        ll ans=0;
        for(char c:s) ans*=26, ans += (c-'a');
        cout << ans;
    }
    return 0;
}