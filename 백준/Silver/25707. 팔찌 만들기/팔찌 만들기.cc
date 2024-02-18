#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());
    int res=0;
    for(int i=1;i<n;i++) res+=v[i]-v[i-1];
    res+=v[n-1]-v[0];
    cout << res;
    return 0;
}