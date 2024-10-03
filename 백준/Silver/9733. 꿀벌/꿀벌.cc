#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    map<string,int> m;
    string s;
    double tot=0;
    while(cin >> s) m[s]++, tot++;

    for(auto s:vector<string>({"Re","Pt","Cc","Ea","Tb","Cm","Ex"})) {
        cout << s << ' ' << m[s] << ' ' << fixed << setprecision(2) << m[s]/tot << '\n';
    }
    cout << "Total " << (int)tot << " 1.00";
    return 0;
}