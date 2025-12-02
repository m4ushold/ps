#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

void sol(int tc) {
    cout << "Case #" << tc << ": ";
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    while(1) {
        int mx=*max_element(all(v));
        if(mx==0) break;
        vector<char> t;
        for(int i=0;i<n;i++) if(v[i] == mx) t.push_back(i+'A');
        v[t[0]-'A']--;
        if(t.size() & 1) cout << t[0] << ' ';
        else cout << t[0] << t[1] << ' ', v[t[1]-'A']--;
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}