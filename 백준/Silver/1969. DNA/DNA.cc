#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    vector<string> v(n);
    string res="";
    int cnt=0;
    for(auto &i:v) cin >> i;
    for(int i=0;i<m;i++) {
        vector<int> a(202);
        int mx=0;
        for(auto j:v) mx=max(mx,++a[j[i]]);
        for(char c:{'A', 'C', 'G', 'T'}) if(mx==a[c]) {res+=c, cnt+=n-mx; break;}
    }
    cout << res << "\n" << cnt;
    return 0;
}