#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &v) {
    int n=v.size(), mx=0;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) for(int k=j+1;k<n;k++) mx=max(mx,(v[i]+v[j]+v[k])%10);
    return mx;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> res;
    for(int i=1;i<=n;i++) {
        vector<int> v(5);
        for(int &i:v) cin >> i;
        res.push_back({f(v),i});
    }
    sort(res.begin(),res.end(),greater<>());
    cout << res[0].second;
    return 0;
}