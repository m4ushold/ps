#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x,y; cin >> x >> y;
    vector<pair<int,int>> v(3);
    for(auto &[a,b]:v) cin >> a >> b;
    sort(v.begin(),v.end());
    double mn=1e9;
    do {
        int xx=x, yy=y;
        double s=0;
        for(auto [i,j]:v) s+=hypot(xx-i, yy-j), xx=i, yy=j;
        mn=min(mn, s);
    } while(next_permutation(v.begin(),v.end()));
    cout << floor(mn);
    return 0;
}