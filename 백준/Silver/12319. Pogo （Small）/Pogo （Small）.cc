#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int tc=1;tc<=t;tc++) {
        int a,b; cin >> a >> b;
        cout << "Case #" << tc << ": ";
        string x=a>0?"WE":"EW";
        for(int i=0;i<abs(a);i++) cout << x;
        string y=b>0?"SN":"NS";
        for(int i=0;i<abs(b);i++) cout << y;
        cout << '\n';
    }
    return 0;
}