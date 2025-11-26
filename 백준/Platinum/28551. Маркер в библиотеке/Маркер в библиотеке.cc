#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

string f(string &s) {
    char c = *min_element(all(s));
    int n = s.size();
    string res, t;
    vector<string> v;
    for(int i=0;i<n;i++) {
        if(s[i] == c) {
            res += c;
            if(t.size()) v.push_back(t), t.clear();
        } else t += s[i];
    }
    if(t.size()) v.push_back(t);
    for(string t:v) res += f(t);
    return res;
}

void sol(int tc) {
    string s; cin >> s;
    cout << f(s);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}