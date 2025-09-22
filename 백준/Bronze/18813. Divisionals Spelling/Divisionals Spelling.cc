#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

void sol(int tc) {
    int n,m; cin >> n >> m;
    int cnt=0;
    for(int i=0;i<n;i++) {
        string s; cin >> s;
        if(set<char>(s.begin(),s.end()).size() == s.size()) {
            int f=1;
            for(char c:s) if(c > 'A'+m-1) f=0;
            cnt += f;
        }
    }
    cout << cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}