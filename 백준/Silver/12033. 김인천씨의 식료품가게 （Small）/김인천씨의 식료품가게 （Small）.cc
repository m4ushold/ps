#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int k=1;k<=t;k++) {
        int n; cin >> n;
        n*=2;
        vector<int> v(n), vi(n), res;
        for(int &i:v) cin >> i;
        for(int i=0;i<n;i++) {
            if(vi[i]) continue;
            vi[i]=1;
            for(int j=i+1;j<n;j++) if(!vi[j] && v[i]/3*4==v[j]) {
                vi[j]=1; break;
            }
            res.push_back(v[i]);
        }
        cout << "Case #" << k << ": ";
        for(int i:res) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}