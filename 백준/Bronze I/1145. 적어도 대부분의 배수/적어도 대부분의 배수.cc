#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v(5);
    for(int &i:v) cin >> i;
    int mn=1e9;
    for(int i=0;i<5;i++) for(int j=i+1;j<5;j++) for(int k=j+1;k<5;k++) mn=min(mn,lcm(lcm(v[i],v[j]),v[k]));
    cout << mn;
    return 0;
}