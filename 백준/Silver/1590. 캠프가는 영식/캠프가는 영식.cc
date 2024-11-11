#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, t; cin >> n >> t;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int a,d,c; cin >> a >> d >> c;
        for(int j=a;c;j+=d,c--) v.push_back(j);
    }
    sort(v.begin(),v.end());
    auto it = lower_bound(v.begin(),v.end(),t);
    if(it == v.end()) cout << -1;
    else cout << *it-t;
    return 0;
}