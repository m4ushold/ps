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

vector<ll> f(poly &a) {
    int n=1<<(__lg(a.size()+a.size())+(__popcount(a.size()+a.size())!=1));
    a.resize(n);
    fft(a, 0);
    for(int i=0;i<n;i++) a[i]*=a[i];
    fft(a, 1);

    vector<ll> res(n);
    for(int i=0;i<n;i++) res[i]=round(a[i].real());
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> v(n), s(n);
    for(ll i=1;i<n;i++) v[i*i%n]++, s[2*i*i%n]++;

    poly p(n);
    for(int i=0;i<n;i++) p[i]=v[i];
    vector<ll> vec=f(p);
    
    ll dap=0;
    for(ll i=1;i<n;i++) {
        ll a=i*i%n, b=vec[a]+vec[n+a];
        dap+=(b-s[a])/2+s[a];
    }
    cout << dap;
    return 0;
}