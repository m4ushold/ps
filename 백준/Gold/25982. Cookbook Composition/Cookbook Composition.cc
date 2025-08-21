#include <bits/stdc++.h>
using namespace std;
using ll=long long;

pair<ll,ll> f(int n) {
    map<string,ll> in, dp, time;
    map<string,vector<string>> g;
    ll tot=0;
    for(int i=0,t,m;i<n;i++) {
        string s; cin >> s >> t >> m;
        for(int j=0;j<m;j++) {
            string ss; cin >> ss;
            g[ss].push_back(s);
        }
        in[s]=m, time[s]=t;
        tot+=t;
    }
    queue<string> q;
    for(auto [i,j]:in) if(!j) q.push(i), dp[i]=time[i];
    while(q.size()) {
        string v = q.front(); q.pop();
        for(string i:g[v]) {
            if(--in[i] == 0) q.push(i);
            dp[i] = max(dp[i], dp[v] + time[i]);
        }
    }
    ll mx=0;
    for(auto [i,j]:dp) mx=max(mx,j);
    return {tot,mx};
}

void sol(int tc) {
    int n; cin >> n;
    vector<tuple<ll,ll,string>> v;
    for(int i=0,x;i<n;i++) {
        string s; cin >> s >> x;
        auto [a,b] = f(x);
        v.push_back({a,b,s});
    }
    sort(v.begin(),v.end(),[](auto a, auto b) {
        auto [aa,ab,ac]=a;
        auto [ba,bb,bc]=b;
        return aa*bb < ab*ba;
    });
    for(auto [a,b,c]:v) cout << c << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}