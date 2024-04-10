#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> dice(n);
    for(auto &v:dice) {
        v.resize(7);
        int a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;
        v[a]=f, v[f]=a, v[b]=d, v[d]=b, v[c]=e, v[e]=c;
    }

    int res=0;
    for(int i=1;i<=6;i++) {
        int a=0, t=i;
        for(auto v:dice) {
            if(t+v[t]==11) a+=4;
            else if(t==6 || v[t]==6) a+=5;
            else a+=6;
            t=v[t];
        }
        res=max(res,a);
    }
    cout << res;
    return 0;
}