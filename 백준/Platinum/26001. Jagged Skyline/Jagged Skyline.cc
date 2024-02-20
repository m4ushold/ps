#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll W, H;

ll f(int x, ll mn=0) {
    ll s=mn, e=H;
    while(s<e) {
        string str;
        ll m=(s+e+1)/2;
        cout << "? " << x << ' ' << m << endl;
        cin >> str;
        if(str!="sky") s=m;
        else e=m-1;
    }
    return e;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> W >> H;
    vector<int> v(W);
    random_device rd;
    mt19937 g(rd());
    iota(v.begin(),v.end(),1);
    shuffle(v.begin(),v.end(),g);

    ll x=v[0], y=f(x);
    for(int i=1;i<W;i++) {
        if(y==H) break;
        cout << "? " << v[i] << ' ' << y+1 << endl;
        string s; cin >> s;
        if(s=="sky") continue;
        else x=v[i], y=f(x,y+1);
    }
    cout << "! " << x << ' ' << y << endl;
    return 0;
}