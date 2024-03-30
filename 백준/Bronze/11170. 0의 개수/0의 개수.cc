#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int f(int i) {
    int res=0;
    for(char c:to_string(i)) res+=c=='0';
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n,m,cnt=0; cin >> n >> m;
        for(int i=n;i<=m;i++) cnt+=f(i);
        cout << cnt << '\n';
    }
    return 0;
}