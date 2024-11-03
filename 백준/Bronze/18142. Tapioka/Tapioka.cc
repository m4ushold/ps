#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string a,b,c; cin >> a >> b >> c;
    string s;
    for(auto i:{a,b,c}) {
        if(i=="tapioka" || i=="bubble") continue;
        s+=i, s+=' ';
    }
    if(s.empty()) cout << "nothing";
    else cout << s;
    return 0;
}