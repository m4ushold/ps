#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c,d,k; cin >> a >> b >> c >> d >> k;
    int l=max(a,c), r=min(b,d);
    if(l>r) cout << 0;
    else if(l<=k && k<=r) cout << r-l;
    else cout << r-l+1;
    return 0;
}