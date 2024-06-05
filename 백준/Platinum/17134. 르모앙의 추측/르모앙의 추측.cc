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

poly operator*(poly a, poly b) {
    int n=1<<(__lg(a.size()+b.size())+(__popcount(a.size()+b.size())!=1));
    a.resize(n), b.resize(n);
    fft(a,0), fft(b,0);
    for(int i=0;i<n;i++) a[i]*=b[i];
    fft(a,1);
    return a;
}


const int SZ=1010101;
int S[SZ]={1,1};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    poly f(SZ), g(SZ);
    for(int i=2;i*i<SZ;i++) if(!S[i]) for(int j=2*i;j<=SZ;j+=i) S[j]=1;

    for(int i=3;i<SZ;i++) if(!S[i]) f[i]=g[min(i*2,SZ)]=cpx(1,0);
    g[4]=cpx(1,-0);

    poly h=f*g;
    int t, n; cin >> t;
    while(t--) cin >> n, cout << round(h[n].real()) << '\n';

    return 0;
}