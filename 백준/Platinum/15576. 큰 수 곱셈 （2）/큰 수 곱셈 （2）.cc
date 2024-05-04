#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using cpx=complex<double>;
using poly=vector<cpx>;

void fft(poly &f, bool inv) {
    int n=f.size();
    poly buc(n);
    for(int s=n;s>=2;s/=2) {
        for(int i=0;i<n;i+=s) {
            int pos=0;
            for(int j=0;j<s;j+=2) buc[pos++]=f[i+j];
            for(int j=1;j<s;j+=2) buc[pos++]=f[i+j];
            for(int j=0;j<s;j++) f[i+j]=buc[j];
        }
    }

    for(int s=2;s<=n;s*=2) {
        cpx w(cos(2*M_PI/s), sin(2*M_PI/s));
        for(int i=0;i<n;i+=s) {
            cpx wp(1,0);
            for(int j=0;j<s/2;j++, wp*=w) {
                cpx a=f[i+j], b=f[i+j+s/2];
                f[i+j]=a+wp*b;
                f[i+j+s/2]=a-wp*b;
            }
        }
    }

    if(inv) {
        reverse(f.begin()+1,f.end());
        for(int i=0;i<n;i++) f[i]/=n;
    }
}

poly operator*(poly a, poly b) {
    int n=1<<(__lg(a.size()+b.size())+(__popcount(a.size()+b.size())!=1));
    a.resize(n), b.resize(n);

    fft(a,0), fft(b,0);
    for(int i=0;i<n;i++) a[i]*=b[i];
    fft(a,1);
    return a;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s1,s2; cin >> s1 >> s2;
    if(s1=="0" || s2=="0") {cout << 0; return 0;}

    poly a(s1.size()), b(s2.size());
    for(int i=0;i<s1.size();i++) a[i]=s1[i]-'0';
    for(int i=0;i<s2.size();i++) b[i]=s2[i]-'0';
    
    vector<ll> c;
    for(auto i:a*b) c.push_back(round(i.real()));
    c.resize(s1.size()+s2.size()-1);
    for(int i=c.size()-1;i;i--) c[i-1]+=c[i]/10, c[i]%=10;
    for(ll i:c) cout << i;
    return 0;
}