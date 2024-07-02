#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,l=0,r=0; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    int mx=0;
    for(int i:v) if(i>mx) l++, mx=i;
    reverse(v.begin(),v.end());
    mx=0;
    for(int i:v) if(i>mx) r++, mx=i;
    cout << l << '\n' << r;
    return 0;
}