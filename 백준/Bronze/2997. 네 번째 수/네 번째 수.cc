#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v(3);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());
    if(v[1]-v[0] == v[2]-v[1]) cout << v[2]+v[2]-v[1];
    else if(abs(v[1]-v[0]) > abs(v[2]-v[1])) cout << v[0]+v[2]-v[1];
    else cout << v[1]+v[1]-v[0];
    return 0;
}