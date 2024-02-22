#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<pair<int,int>> v(5);
    for(int i=0,a;i<5;i++) {
        for(int j=0;j<4;j++) cin >> a, v[i].first+=a;
        v[i].second=i+1;
    }
    sort(v.begin(),v.end(),greater<>());
    cout << v[0].second << ' ' << v[0].first;

    return 0;
}