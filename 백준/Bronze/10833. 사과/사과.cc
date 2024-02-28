#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,s=0; cin >> n;
    for(int i=0,a,b;i<n;i++) {
        cin >> a >> b;
        s+=b%a;
    }
    cout <<s;

    return 0;
}