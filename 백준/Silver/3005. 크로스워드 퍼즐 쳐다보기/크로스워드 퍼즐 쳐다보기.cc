#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    vector<string> v(n);
    for(auto &s:v) cin >> s;

    vector<string> ans;
    for(int i=0;i<n;i++) {
        string tmp;
        for(int j=0;j<m;j++) {
            if(v[i][j]=='#') {
                if(tmp.length()>1) ans.push_back(tmp);
                tmp.clear();
            } else tmp+=v[i][j];
        }
        if(tmp.size()>1) ans.push_back(tmp);
    }
    for(int i=0;i<m;i++) {
        string tmp;
        for(int j=0;j<n;j++) {
            if(v[j][i]=='#') {
                if(tmp.length()>1) ans.push_back(tmp);
                tmp.clear();
            } else tmp+=v[j][i];
        }
        if(tmp.size()>1) ans.push_back(tmp);
    }
    sort(ans.begin(),ans.end());
    cout << ans[0];
    return 0;
}