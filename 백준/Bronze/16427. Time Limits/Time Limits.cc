#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,s; cin >> n >> s;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    int a=*max_element(v.begin(),v.end())*s;
    cout << a/1000 + (a%1000 ? 1 : 0);
    return 0;
}