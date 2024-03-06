#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int f=0, cnt=0;
    for(int i=0,a;i<n;i++) cin >> a, f|=a==7;
    if(f) cnt++, f=0;
    for(int i=0,a;i<n;i++) cin >> a, f|=a==7;
    if(f) cnt++, f=0;
    for(int i=0,a;i<n;i++) cin >> a, f|=a==7;
    if(f) cnt++, f=0;
    cout << (cnt==3?777:0);

    return 0;
}