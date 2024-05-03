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
    int n=1<<(__lg(a.size()+b.size())+1);
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
    ll n,ans=0; cin >> n;
    poly a(n*2),b(n*2),c;

    for(int i=0,c;i<n;i++) cin >> a[i];
    for(int i=n;i<2*n;i++) a[i]=a[i-n];
    for(int i=n*2-1;i>=n;i--) cin >> b[i];

    c=a*b;
    for(auto i:c) ans=max(ans,(ll)round(i.real()));
    cout << ans;
    return 0;
}