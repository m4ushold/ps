#include <bits/stdc++.h>
using namespace std;
using ll=long long;

map<string,pair<ll,ll>> m({
    {"black",{0,1}},
    {"brown",{1,10}},
    {"red",{2,100}},
    {"orange",{3,1000}},
    {"yellow",{4,10000}},
    {"green",{5,100000}},
    {"blue",{6,1000000}},
    {"violet",{7,10000000}},
    {"grey",{8,100000000}},
    {"white",{9,1000000000}}
});

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b,c; cin >> a >> b >> c;
    cout << (m[a].first*10+m[b].first)*m[c].second;
    return 0;
}