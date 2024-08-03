#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,a; cin >> n >> a;
    if(n<6) {
        for(int i=1,b=a^1;i<n;i++,b^=1) cout << b << '\n';
    } else cout << "Love is open door";
    return 0;
}