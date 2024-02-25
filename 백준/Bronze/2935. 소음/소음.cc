#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b,o; cin >> a >> o >> b;
    if(o=="*") cout << 1 << string(a.size()+b.size()-2,'0');
    else if(a.size()==b.size()) cout << 2 << string(a.size()-1,'0');
    else {
        if(a.size()<b.size()) swap(a,b);
        a[a.size()-b.size()]='1';
        cout << a;
    }
    return 0;
}