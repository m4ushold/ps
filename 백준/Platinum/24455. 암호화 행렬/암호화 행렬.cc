#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Matrix
{
    int sz;
    vector<vector<ll>> m;
    const vector<ll>& operator[](int i) const {return m[i];}
    void in(int n) {
        sz=n;
        m.resize(n);
        for(int i=0;i<n;i++) {
            m[i].resize(n);
            for(ll &j:m[i]) cin >> j;
        }
    }
};

ll operator* (const vector<ll> &a, const vector<ll> &b) {
    ll res=0;
    for(int i=0;i<a.size();i++) res+=a[i]*b[i];
    return res;
}

vector<ll> operator* (const Matrix &a, const vector<ll> &b) {
    vector<ll> res(a.sz);
    for(int i=0;i<a.sz;i++) res[i]=(a[i])*b;
    return res;
}

bool operator != (const vector<ll> &a, const vector<ll> &b) {
    for(int i=0;i<a.size();i++) if(a[i]!=b[i]) return 1;
    return 0;
}

bool chk(const Matrix &a, const Matrix &b, const Matrix &c) {
    random_device rd;
    mt19937 g(rd());
    uniform_int_distribution<int> bi(0,1);
    
    for(int i=0;i<50;i++) {
        vector<ll> r(a.sz);
        for(ll &i:r) i=bi(g);
        if(a*(b*r) != c*r) return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    Matrix a,b,c;
    a.in(n), b.in(n), c.in(n);
    int aa=0,bb=0,cc=0;
    if(chk(a,b,c)) aa|=1, bb|=2, cc|=4;
    if(chk(b,a,c)) aa|=2, bb|=1, cc|=4;
    if(chk(a,c,b)) aa|=1, bb|=4, cc|=2;
    if(chk(c,a,b)) aa|=2, bb|=4, cc|=1;
    if(chk(b,c,a)) aa|=4, bb|=1, cc|=2;
    if(chk(c,b,a)) aa|=4, bb|=2, cc|=1;
    cout << aa << '\n' << bb << '\n' << cc;
    return 0;
}