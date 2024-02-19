#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,s; cin >> n >> s;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());
    int res=0;
    for(int i=0,j=n-1;i<n;i++) {
        while(v[i]+v[j]>s && i<j) --j;
        res+=max(0,j-i);
    }
    cout << res;
    return 0;
}