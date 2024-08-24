#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int s=1,e=n;
    while(s<e) {
        int m=s+e>>1;
        cout << "? " << m << endl;
        int shp; cin >> shp;
        if(shp == m-shp) {cout << "! " << m << endl; break;}

        if(m-shp > shp) e=m;
        else s=m;
    }
    return 0;
}