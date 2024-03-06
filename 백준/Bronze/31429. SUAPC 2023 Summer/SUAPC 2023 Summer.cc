#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<pair<int,int>> v({{12, 1600},{11, 894},{11, 1327},{10, 1311},{9, 1004},{9, 1178},{9, 1357},{8, 837},{7, 1055},{6, 556},{6, 773}});
    int n; cin >> n;
    cout << v[n-1].first << ' ' << v[n-1].second;
    return 0;
}