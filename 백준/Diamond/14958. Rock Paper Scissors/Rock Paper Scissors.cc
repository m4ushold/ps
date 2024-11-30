#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using cpx=complex<double>;
using poly=vector<cpx>;

void fft(poly &f, bool inv) {
    int n = f.size();
    for(int i=1, j=0; i<n; i++) {
        int bit = n/2;
        while(j >= bit) j -= bit, bit /= 2;
        j += bit;
        if(i < j) swap(f[i], f[j]);
    }

    for(int k=1; k<n; k*=2) {
        cpx w(cos(inv ? M_PI/k : -M_PI/k), sin(inv ? M_PI/k : -M_PI/k));
        for(int i=0; i<n; i+=k*2) {
            cpx wp(1, 0);
            for(int j=0; j<k; j++,wp*=w) {
                cpx a=f[i+j], b=f[i+j+k]*wp;
                f[i+j]=a+b, f[i+j+k]=a-b;
            }
        }
    }

    if(inv) for(int i=0; i<n; i++) f[i] /= n;
}

vector<ll> operator*(poly &a, poly &b) {
    int n=1<<(__lg(a.size()+b.size())+(__popcount(a.size()+b.size())!=1));
    a.resize(n), b.resize(n);
    fft(a,0), fft(b,0);
    for(int i=0;i<n;i++) a[i]*=b[i];
    fft(a,1);

    vector<ll> res(n);
    for(int i=0;i<n;i++) res[i] = int(a[i].real() + (a[i].real()>0 ? 0.5 : -0.5));
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    string rps, my; cin >> rps >> my;
    reverse(my.begin(),my.end());
    poly a(n), b(m), c(n), d(m), e(n), f(m);

    // (r,p), (p,s), (s,r)
    for(int i=0;i<n;i++) {
        if(rps[i]=='R') a[i]=1;
        else if(rps[i]=='P') c[i]=1;
        else e[i]=1;
    }
    for(int i=0;i<m;i++) {
        if(my[i]=='P') b[i]=1;
        else if(my[i]=='S') d[i]=1;
        else f[i]=1;
    }

    auto aa=a*b, bb=c*d, cc=e*f;
    ll mx=0;
    for(int i=m-1;i<m+n-1;i++) {
        mx=max(mx, aa[i]+bb[i]+cc[i]);
    }
    cout << mx;
    return 0;
}