#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> X, Y;
map<tuple<int,int,int>,int> vis;
vector<pair<int,int>> dd({{1,0},{0,-1},{-1,0},{0,1}});

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=0,x,y;i<n;i++) {
        cin >> x >> y;
        X[x].push_back(y);
        Y[y].push_back(x);
    }

    for(auto &[i,j]:X) sort(j.begin(),j.end());
    for(auto &[i,j]:Y) sort(j.begin(),j.end());

    int x=0,y=0,dir=0,cnt=0;;
    while(1) {
        if(vis[{x,y,dir}]) {
            cout << "oo";
            return 0;
        }
        vis[{x,y,dir}] = 1;
        if(dir&1) { // ver
            vector<int> &v = X[x];
            int j = upper_bound(v.begin(),v.end(),y)-v.begin();
            if(dir==1) {
                if(j == 0) break;
                y=v[j-1]+1;
            } else {
                if(j == v.size()) break;
                y=v[j]-1;
            }
        } else { // hor
            vector<int> &v = Y[y];
            int j = upper_bound(v.begin(),v.end(),x)-v.begin();
            if(dir == 0) {
                if(j == v.size()) break;
                x=v[j]-1;
            } else {
                if(j == 0) break;
                x=v[j-1]+1;
            }
        }
        cnt++, dir=(dir+1)%4;
    }
    cout << cnt;
    return 0;
}