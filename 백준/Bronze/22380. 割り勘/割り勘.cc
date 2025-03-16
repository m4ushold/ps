#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; 
    while(cin >> n >> m && n) {
        vector<int> v(n);
        int sum=0;
        for(int i:v) {
            cin >> i;
            sum+=min(i,m/n);
        }
        cout << sum << '\n';
    }
    return 0;
}