#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) {
        vector<int> v(3);
        for(int &i:v) cin >> i;
        sort(v.begin(),v.end());
        cout << "Scenario #" << i << ":\n";
        cout << (v[0]*v[0]+v[1]*v[1]==v[2]*v[2] ? "yes\n\n" : "no\n\n");
    }
    return 0;
}