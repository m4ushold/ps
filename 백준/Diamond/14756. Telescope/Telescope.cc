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

vector<ll> operator*(poly a, poly b) {
    int n=1<<(__lg(a.size()+b.size())+(__popcount(a.size()+b.size())!=1));
    a.resize(n), b.resize(n);
    fft(a,0), fft(b,0);
    for(int i=0;i<n;i++) a[i]*=b[i];
    fft(a,1);

    vector<ll> res;
    for(int i=0;i<n;i++) res.push_back(round(a[i].real()));
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,l,w; cin >> n >> l >> m >> w;
    vector<poly> a,b;
    for(ll i=0;i<m;i++) {
        a.emplace_back();
        for(ll j=0,x;j<n;j++) cin >> x, a.back().push_back(cpx(x));
    }
    for(ll i=0;i<m;i++) {
        b.emplace_back();
        for(ll j=0,x;j<l;j++) cin >> x, b.back().push_back(cpx(x));
        reverse(b.back().begin(),b.back().end());
    }

    vector<vector<ll>> res;
    for(int i=0;i<m;i++) res.push_back(a[i]*b[i]);

    int cnt=0;
    for(int j=l-1;j<n;j++) {
        ll sum=0;
        for(int i=0;i<m;i++) sum+=res[i][j];
        if(sum > w) cnt++;
    }
    cout << cnt;
    return 0;
}