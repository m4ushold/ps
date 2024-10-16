#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int cnt=0, tt=0, t=0;
    vector<int> v;
    for(int i=0;i<=n;i++) {
        string a,b; cin >> a >> b;
        if(b=="teacher") tt=stoi(a.substr(0,2))*60 + stoi(a.substr(3));
        else v.push_back(stoi(a.substr(0,2))*60 + stoi(a.substr(3)));
    }
    string a; cin >> a;
    t=stoi(a.substr(0,2))*60 + stoi(a.substr(3));
    sort(v.begin(),v.end());
    cout << min(v.end()-lower_bound(v.begin(),v.end(),tt),v.end()-lower_bound(v.begin(),v.end(),t));
    return 0;
}