#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(int &i:v) cin >> i;
        cout << *min_element(v.begin(),v.end()) << " " << *max_element(v.begin(),v.end()) << '\n';
    }
    return 0;
}