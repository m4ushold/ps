#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, cnt=0; cin >> n;
    string a,b; cin >> a >> b;
    for(int i=0;i<n;i++) cnt+=a[i]!=b[i];
    cout << cnt;
    return 0;
}