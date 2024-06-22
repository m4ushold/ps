#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    int s=accumulate(v.begin(),v.end(),0);
    if(!n || !s) cout << "divide by zero";
    else cout << "1.00";
    return 0;
}