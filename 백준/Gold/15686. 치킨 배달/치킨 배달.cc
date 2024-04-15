#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<pair<int,int>> h, c;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
        int a; cin >> a;
        if(a==1) h.emplace_back(i,j);
        else if(a==2) c.emplace_back(i,j);
    }

    vector<int> b(c.size());
    for(int i=0;i<m;i++) b[i]=1;
    int dap=1e9;
    do {
        int mx=0;
        for(auto [x,y]:h) {
            int mn=1e9;
            for(int i=0;i<c.size();i++) if(b[i]) mn=min(mn,abs(x-c[i].first)+abs(y-c[i].second));
            mx+=mn;
        }
        dap=min(dap,mx);
    } while(prev_permutation(b.begin(),b.end()));
    cout << dap;
    return 0;
}