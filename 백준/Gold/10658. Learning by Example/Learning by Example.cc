#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,a,b; cin >> n >> a >> b;
    vector<pair<int,int>> v(n);
    for(auto &[i,j]:v) {
        string s; cin >> s >> i;
        j=s=="S";
    }
    sort(v.begin(),v.end());

    int res=0;
    for(int i=0;i<n;i++) {
        if(!v[i].second) continue;

        int l=-1, r=1e9+1;
        if(i) l=(v[i-1].first+v[i].first+1)>>1;
        if(i<n-1) r=v[i].first+v[i+1].first>>1;
        res+=max(min(b,r)-max(a,l)+1,0);
    }

    for(int i=1;i<n;i++) {
        int m=(v[i-1].first+v[i].first)/2;
        if(v[i-1].second && v[i].second && ~(v[i-1].first+v[i].first)&1 && a<=m && m<=b) res--;
    }
    cout << res;
    return 0;
}