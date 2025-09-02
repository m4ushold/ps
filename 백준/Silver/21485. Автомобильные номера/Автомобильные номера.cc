#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    string s; cin >> s;
    string d,a;
    for(char c:s) (isalpha(c)?a:d).push_back(c);
    vector<string> dd,aa;
    sort(d.begin(),d.end()), sort(a.begin(),a.end());
    do {
        dd.push_back(d);
    } while(next_permutation(d.begin(),d.end()));
    do {
        aa.push_back(a);
    } while(next_permutation(a.begin(),a.end()));

    cout << aa.size()*dd.size() << '\n';
    for(auto ddd:dd) for(auto aaa:aa) {
        int i=0,j=0;
        string res;
        for(char c:s) {
            if(isdigit(c)) res+=ddd[i++];
            else res+=aaa[j++];
        }
        cout << res << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}