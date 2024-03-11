#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        ll x,y;
        string tmp;
        for(int i=0;i<m;i++) {
            char c; cin >> c;
            tmp+=c;
        }
        x=stoll(tmp);
        tmp="";
        for(int i=0;i<m;i++) {
            char c; cin >> c;
            tmp+=c;
        }
        y=stoll(tmp);

        string s;
        for(int i=0;i<n;i++) {
            char c; cin >> c;
            s+=c;
        }
        s+=s;
        int cnt=0;
        for(int i=0;i<n;i++) {
            ll z=stoll(s.substr(i,m));
            if(x<=z && z<=y) ++cnt;
        }
        cout << cnt << '\n';
    }
    return 0;
}