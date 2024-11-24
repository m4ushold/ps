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


constexpr int sz = 1010101;
vector<int> prime;
poly v(1'000'000);
int sp[sz], s[sz];


poly f(poly &a) {
    int n=1<<(__lg(a.size()+a.size())+(__popcount(a.size()+a.size())!=1));
    a.resize(n);
    fft(a, 0);
    for(int i=0;i<n;i++) a[i]*=a[i];
    fft(a, 1);
    return a;
}

void Sieve(ll n) {
    for(int i=2; i<=n; i++){
        if(!sp[i]){
            prime.push_back(i);
            v[i]=1;
            s[i]=1;
        }
        for(auto j : prime){
            if(i*j >= sz) break;
            sp[i*j] = j;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    Sieve(1'000'000);
    v=f(v);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << (round(v[n].real()) + s[n/2])/2 << '\n';
    }
    return 0;
}