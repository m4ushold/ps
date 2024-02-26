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
    int n;
    while(cin >> n && n) {
        Matrix a,b;
        a.in(n), b.in(n);
        cout << (chk(a,a,b) ? "YES\n" : "NO\n");
    }
    return 0;
}