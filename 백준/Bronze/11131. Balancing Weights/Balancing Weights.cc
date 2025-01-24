#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(int &i:v) cin >> i;
        int sum=accumulate(v.begin(),v.end(),0);
        if(sum == 0) cout << "Equilibrium\n";
        else if(sum > 0) cout << "Right\n";
        else cout << "Left\n";
    }
    return 0;
}