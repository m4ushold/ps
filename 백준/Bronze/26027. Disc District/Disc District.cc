#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ostream& operator<<(ostream &os, const pair<int, int> &p) {
    return cout << "(" << p.first << ' ' << p.second << ")";
}

template<typename T>
ostream& operator<<(ostream &cout, const vector<T> v) {
    for(auto i:v) cout << i << ' ';
    return cout;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll r; cin >> r;
    ll x=r+1, y=0, dist=(r+1)*(r+1);
    for(ll yy=0;yy<=r;yy++) {
        ll xx=sqrt(r*r-yy*yy);
        while(xx*xx+yy*yy <= r*r) xx++;

        if(xx*xx+yy*yy < dist) x=xx, y=yy, dist=xx*xx+yy*yy;
    }
    
    cout << x << ' ' << y;
    return 0;
}