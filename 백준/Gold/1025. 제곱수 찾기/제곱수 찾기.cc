#include <bits/stdc++.h>
using namespace std;
using ll=long long;;

bool f(ll n) {
    ll a=sqrt(n);
    return a*a==n;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<string> v(n);
    for(auto &s:v) cin >> s;
    ll dap = -1;
    for(int r1=0;r1<n;r1++) for(int c1=0;c1<m;c1++) {
        for(int dr=-n;dr<n;dr++) for(int dc=-m;dc<m;dc++) {
            if(!dr && !dc) continue;
            string t;
            int r = r1, c = c1;
            while(r >= 0 && r < n && c >= 0 && c < m) {
                t.push_back(v[r][c]);
                ll num = stoll(t);
                if(f(num)) dap = max(dap, num);
                r += dr, c += dc;
            }
        }
    }
    cout << dap;
    return 0;
}