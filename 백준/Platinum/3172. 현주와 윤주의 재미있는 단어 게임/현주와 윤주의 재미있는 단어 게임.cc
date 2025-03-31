#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<17;
struct {
    int T[sz];
    void add(int i, int x) {
        for(;i<sz;i+=i&-i) T[i]+=x;
    }
    int sum(int i) {
        int res=0;
        for(;i;i-=i&-i) res+=T[i];
        return res;
    }
} fw;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<string> v(n);
    for(auto &i:v) cin >> i;
    sort(v.begin(),v.end());
    vector<pair<string,int>> u;
    for(int i=0;i<n;i++) {
        reverse(v[i].begin(),v[i].end());
        u.push_back({v[i],i+1});
    }

    sort(u.begin(),u.end());
    ll ans=0;
    for(auto [s,i]:u) {
        ans += fw.sum(sz-1) - fw.sum(i);
        fw.add(i, 1);
    }
    cout << ans;
    return 0;
}