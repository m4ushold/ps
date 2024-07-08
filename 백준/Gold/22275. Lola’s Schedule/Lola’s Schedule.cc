#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int D[202020];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,x; cin >> n >> x;
    vector<pair<int,int>> v(n);
    int y=0;
    for(auto &[s,e]:v) {
        cin >> s >> e;
        for(int i=s;i<=s+e;i++) D[i]=1;
        y=max(y,s+e);
    }

    int mn=1e9, dap=0;
    for(int i=0;i<=480;i++) {
        int j=i, s=0;
        while(j<=y) s+=D[j], j+=x;
        if(mn>s) mn=s, dap=i;
    }
    cout << dap << ' ' << mn;
    return 0;
}