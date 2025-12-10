#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
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
    int n=1;
    while(n<a.size()+b.size()) n<<=1;
    a.resize(n), b.resize(n);
    fft(a,0), fft(b,0);
    for(int i=0;i<n;i++) a[i]*=b[i];
    fft(a,1);
    return a;
}

void sol(int tc) {
    int n;
poly a, b;

  cin.tie(0); cout.tie(0);

  cin >> n;
  // a = vector<int>(n);
  // b = vector<int>(n);
  a = b = poly(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = cpx(x, 0);
  }
  for (int i = 0; i < n; i++) a.push_back(a[i]);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b[i] = cpx(x, 0);
  }
  reverse(b.begin(), b.end());
  auto x = a*b;
  int r = 0;
  for (int i = n; i < 2*n; i++) r = max(r, (int)round(x[i].real()));
  cout << r;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}