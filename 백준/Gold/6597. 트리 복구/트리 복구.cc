#include <bits/stdc++.h>
using namespace std;

void rec(string pre, string in) {
    char a = pre[0];
    if(in.size()==1 || pre.size()==1) {
        cout << a;
        return;
    }

    auto it = find(in.begin(),in.end(),a);
    string l(in.begin(), it), r(it+1, in.end());
    
    if(l.size()) rec(pre.substr(1, l.size()), l);
    if(r.size()) rec(pre.substr(pre.size()-r.size()), r);
    cout << a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string a,b;
    while(cin >> a) {
        cin >> b;
        rec(a,b);
        cout << '\n';
    }
    return 0;
}