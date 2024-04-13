#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) {
        vector<int> v(5);
        for(int &i:v) cin >> i;
        cout << "Case #" << i << ": " << *max_element(v.begin(),v.end()) << '\n';
    }
    return 0;
}