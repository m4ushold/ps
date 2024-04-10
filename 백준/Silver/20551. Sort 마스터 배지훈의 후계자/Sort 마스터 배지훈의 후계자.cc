#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());
    for(int i=0,a;i<m;i++) {
        cin >> a;
        if(binary_search(v.begin(),v.end(),a)) cout << lower_bound(v.begin(),v.end(),a)-v.begin() << '\n';
        else cout << "-1\n";
    }
    return 0;
}