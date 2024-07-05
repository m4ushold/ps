#include <bits/stdc++.h>
using namespace std;

int I[1010101];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1,a;i<=n;i++) cin >> a, I[a]=i;
    int cnt=0;
    for(int i=2;i<=n;i++) if(I[i-1] > I[i]) cnt++;
    if(cnt<2) cout << cnt;
    else cout << __lg(cnt)+1;
    return 0;
}