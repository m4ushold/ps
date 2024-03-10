#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<string> v(n);
    set<string> st;
    int j=0;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        if(v[i]=="?") j=i;
        st.insert(v[i]);
    }
    int m; cin >> m;
    while(m--) {
        string s; cin >> s;
        if(n==1) {
            cout << s << '\n';
            return 0;
        }
        if(st.count(s)) continue;
        if(j==0) {
            if(v[j+1].front() == s.back()) {
                cout << s << '\n';
                return 0;
            }
        } else if(j==n-1) {
            if(v[j-1].back() == s[0]) {
                cout << s << '\n';
                return 0;
            }
        } else {
            if(v[j-1].back() == s[0] && v[j+1].front() == s.back()) {
                cout << s << '\n';
                return 0;
            }
        }
    }

    return 0;
}