#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    vector<int> v(m);
    for(int i=0;i<n;i++) {
        string s; cin >> s;
        for(int j=0;j<m;j++) if(s[j] == 'O') v[j]=1;
    }
    if(accumulate(v.begin(),v.end(),0) == m) cout << "ESCAPE FAILED";
    else cout << (find(v.begin(),v.end(),0)-v.begin()+1);
    return 0;
}