#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s="SciComLove";
    if(n&1) reverse(s.begin(),s.end());
    cout << s;
    return 0;
}