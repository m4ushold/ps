#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string a,b; cin >> a >> b;
        cout << "Distances: ";
        for(int i=0;i<a.size();i++) cout << (b[i]-a[i]+26)%26 << ' ';
        cout << '\n';
    }
    return 0;
}