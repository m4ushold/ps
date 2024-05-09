#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,a=0; cin >> n;
    for(int i=0,b;i<n;i++) cin >> b, a^=b;
    cout << (!a ? "cubelover" : "koosaga");
    return 0;
}