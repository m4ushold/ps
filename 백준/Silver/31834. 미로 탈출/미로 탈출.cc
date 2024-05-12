#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, s, e; cin >> n >> s >> e;
        if(min(s,e)==1 && max(s,e)==n) cout << "0\n";
        else if(s==1 || s==n || abs(s-e)==1) cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}