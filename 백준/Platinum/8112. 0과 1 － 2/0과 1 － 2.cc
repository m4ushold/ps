#include <bits/stdc++.h>
using namespace std;
using ll=long long;

string bfs(ll n) {
    vector<ll> p(n), v(n);
    queue<ll> q; q.push(1);
    v[1]=1, p[1]=-1;
    while(q.size()) {
        auto a=q.front(); q.pop();
        if(!a) break;
        if(!v[a*10%n]) q.push(a*10%n), v[a*10%n]=1, p[a*10%n]=a;
        if(!v[(a*10+1)%n]) q.push((a*10+1)%n), v[(a*10+1)%n]=1, p[(a*10+1)%n]=a;
    }

    string s;
    ll x=0;
    while(x!=-1) {
        if(p[x]*10%n==x) s+='0';
        else s+='1';
        x=p[x];
    }
    reverse(s.begin(),s.end());
    return s;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        if(n==1) cout << "1\n";
        else cout << bfs(n) << '\n';
    }
    return 0;
}