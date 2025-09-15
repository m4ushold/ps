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
    int n=2;
    while(n < a.size()+b.size()) n<<=1;
    a.resize(n), b.resize(n);
    fft(a,0), fft(b,0);
    for(int i=0;i<n;i++) a[i]*=b[i];
    fft(a,1);
    return a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    poly a(60'001), c(60'001);
    vector<int> b(60'001);
    int n;
    cin >> n;
    for(int i=0,x;i<n;i++) cin >> x, a[x+30'000]=1;
    cin >> n;
    for(int i=0,x;i<n;i++) cin >> x, b[x+30'000]=1;
    cin >> n;
    for(int i=0,x;i<n;i++) cin >> x, c[x+30'000]=1;
    auto res = a*c;
    ll ans=0;
    for(int i=0;i<b.size();i++) ans += b[i] * round(res[i*2].real());
    cout << ans;
    return 0;
}