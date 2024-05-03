#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using cpx=complex<double>;
using poly=vector<cpx>;

poly dft(const poly &f, cpx w) {
    int n=f.size();
    if(n==1) return f;

    poly a,b,c(n);
    for(int i=0;i<n;i++) i&1 ? a.push_back(f[i]) : b.push_back(f[i]);
    a=dft(a, w*w), b=dft(b,w*w);

    cpx wp(1,0);
    for(int i=0;i<n/2;i++,wp*=w) {
        c[i] = b[i] + wp*a[i];
        c[i+n/2]=b[i]-wp*a[i];
    }
    return c;
}

poly idft(poly f, cpx w) {
    int n=f.size();
    f=dft(f,w);
    reverse(f.begin()+1,f.end());
    transform(f.begin(),f.end(),f.begin(),[&n](auto a){ return a/cpx(n,0); });
    return f;
}

poly operator*(poly& a, poly& b) {
    int n=1<<(__lg(a.size()+b.size())+(__popcount(a.size()+b.size())!=1));
    a.resize(n), b.resize(n);
    poly c(n);

    cpx w(cos(2*M_PI/n), sin(2*M_PI/n));
    poly ap=dft(a,w), bp=dft(b,w);
    for(int i=0;i<n;i++) c[i]=ap[i]*bp[i];
    return idft(c,w);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s1,s2; cin >> s1 >> s2;
    if(s1=="0" || s2=="0") {cout << 0; return 0;}

    poly a(s1.size()), b(s2.size());
    for(int i=0;i<s1.size();i++) a[i]=s1[i]-'0';
    for(int i=0;i<s2.size();i++) b[i]=s2[i]-'0';
    vector<ll> c;
    for(auto i:a*b) c.push_back(round(i.real()));
    c.resize(s1.size()+s2.size()-1);
    for(int i=c.size()-1;i;i--) c[i-1]+=c[i]/10, c[i]%=10;
    for(ll i:c) cout << i;
    return 0;
}