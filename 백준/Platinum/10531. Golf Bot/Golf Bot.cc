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
    int n, m; cin >> n;
    poly f(1<<18);
    for(int i=0,a;i<n;i++) cin >> a, f[a]=1;
    f[0]=1, f=f*f;

	cin >> m;
	int dap=0;
    for(int i=0,a;i<m;i++) {
        cin >> a;
        if(round(f[a].real())) dap++;
    }
    cout << dap;
    return 0;
}