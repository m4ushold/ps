#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a, b;
    vector<tuple<int,int,int>> v(n);
    for(auto &[c,x,y]:v) cin >> x >> y >> c, a.push_back(x), b.push_back(y);
    sort(a.begin(),a.end()), sort(b.begin(),b.end());
    sort(v.begin(),v.end(),greater<>());

    int mn=1e9;
    for(auto x1:a) for(auto x2:a) if(x1<=x2) {
        for(auto y1:b) for(auto y2:b) if(y1<=y2) {
            int cnt=0, w=0;
            for(auto[c,x,y]:v) {
                if(x<x1 || x>x2 || y<y1 || y>y2) cnt++, w+=c;
            }
            
            for(auto [c,x,y]:v) {
                if(w >= 2*(x2+y2-x1-y1)) break;
                if(x1<=x && x<=x2 && y1<=y && y<=y2) cnt++, w+=c;
            }
            mn=min(mn, cnt);
        }
    }
    cout << mn << '\n';
    return 0;
}