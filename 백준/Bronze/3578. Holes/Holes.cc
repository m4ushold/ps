#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    if(!n) cout << 1;
    else if(n==1) cout << 0;
    else if(n&1) cout << 4 << string(n/2,'8');
    else cout << string(n/2,'8');
    return 0;
}