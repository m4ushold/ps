#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

vector<int> A[202];
set<int> S[202];

bool chk(int m) {
    string s = "sogang";
    vector<int> v(m,-1);
    for(char c:"sogan") S[c] = set<int>(all(A[c]));
    for(int i=0;i<s.size();i++) {
        for(int j=0;j<m;j++) {
            auto it = S[s[i]].lower_bound(v[j]);
            if(it == S[s[i]].end()) return 0;
            v[j] = *it;
            S[s[i]].erase(it);
        }
    }
    return 1;
}

void sol(int tc) {
    int n; cin >> n;
    string s; cin >> s;
    for(int i=0;i<n;i++) A[s[i]].push_back(i);
    int l=0, r=n/6;
    while(l<r) {
        int m=l+r+1>>1;
        if(chk(m)) l=m;
        else r=m-1;
    }
    cout << l;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}