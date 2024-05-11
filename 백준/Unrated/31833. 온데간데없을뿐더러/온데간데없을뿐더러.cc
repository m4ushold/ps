#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string a,b;
    for(int i=0,c;i<n;i++) cin >> c, a+=to_string(c);
    for(int i=0,c;i<n;i++) cin >> c, b+=to_string(c);
    cout << min(stoll(a), stoll(b));
    return 0;
}