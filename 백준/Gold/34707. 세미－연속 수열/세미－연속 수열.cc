#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

bool f(set<int> &s) {
    return *s.rbegin()-*s.begin()+1 == s.size();
}

void sol(int tc) {
    int n,k; cin >> n >> k;
    set<int> s;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    for(int i=0;i<k;i++) s.insert(v[i]);
    int l=0,r=k-1;
    for(;r<=n;l++,r++) {
        if(f(s)) {
            cout << "YES" << endl;
            for(int j=l;j<=r;j++) cout << v[j] << ' ';
            cout << endl;
            return;
        }
        s.erase(v[l]);
        if(r+1<n) s.insert(v[r+1]);
    }
    cout << "NO";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}