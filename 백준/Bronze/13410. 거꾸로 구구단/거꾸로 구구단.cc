#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin >> n >> k;
    int mx=0;
    for(int i=1;i<=k;i++) {
        string s=to_string(n*i);
        reverse(s.begin(),s.end());
        mx=max(mx,stoi(s));
    }
    cout << mx;
    return 0;
}