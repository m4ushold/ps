#include <bits/stdc++.h>
using namespace std;

void sol(int tc) {
    cout << "Data Set " << tc << ":\n";
    int n; double w;
    cin >> n >> w;
    vector<double> v(n);
    double ans=0;
    for(auto &i:v) {
        cin >> i;
        ans+=4*M_PI*i*i*i/3;
    }
    if(ans > w*1000) cout << "Yes";
    else cout << "No";
    cout << "\n\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}