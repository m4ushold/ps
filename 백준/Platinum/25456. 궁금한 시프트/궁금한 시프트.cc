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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s1,s2; cin >> s1 >> s2;

    poly a(s1.size()), b(s2.size());
    for(int i=0;i<s1.size();i++) a[i]=s1[i]-'0';
    for(int i=0;i<s2.size();i++) b[i]=s2[i]-'0';
    
    vector<ll> c;
    for(auto i:a*b) c.push_back(round(i.real()));
    cout << *max_element(c.begin(),c.end());
    return 0;
}