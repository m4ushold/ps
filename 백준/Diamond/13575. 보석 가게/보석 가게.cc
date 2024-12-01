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

vector<int> operator*(vector<int> &a, vector<int> &b) {
    int n=1;
    while(n<=max(a.size(),b.size())) n*=2;
    poly aa(a.begin(),a.end()), bb(b.begin(),b.end());
    aa.resize(n), bb.resize(n);
    fft(aa,0), fft(bb,0);
    for(int i=0;i<n;i++) aa[i]*=bb[i];
    fft(aa,1);

    vector<int> res(n);
    for(int i=0;i<n;i++) res[i] = !!round(aa[i].real());
    return res;
}

vector<int> pw(vector<int> a, int n) {
    vector<int> res({1});
    while(n) {
        if(n&1) res=res*a;
        a=a*a, n/=2;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    vector<int> v(n), a(1<<10);
    for(int &i:v) cin >> i, a[i]=1;

    auto res = pw(a, k);
    for(int i=0;i<res.size();i++) {
        if(res[i]) cout << i << ' ';
    }
    return 0;
}