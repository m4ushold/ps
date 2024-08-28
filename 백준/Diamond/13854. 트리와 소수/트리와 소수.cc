#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using cpx=complex<double>;

void FFT(vector<cpx> &a, bool inv_fft=false){
  int N = a.size(); vector<cpx> root(N/2);
  for(int i=1, j=0; i<N; i++){
    int bit = N / 2;
    while(j >= bit) j -= bit, bit >>= 1;
    if(i < (j += bit)) swap(a[i], a[j]);
  }
  long double ang = 2 * acosl(-1) / N * (inv_fft ? -1 : 1);
  for(int i=0; i<N/2; i++) root[i] = cpx(cosl(ang*i), sinl(ang*i));
  
  for(int i=2; i<=N; i<<=1){
    int step = N / i;
    for(int j=0; j<N; j+=i) for(int k=0; k<i/2; k++){
      cpx u = a[j+k], v = a[j+k+i/2] * root[step * k];
      a[j+k] = u+v; a[j+k+i/2] = u-v;
    }
  }
  if(inv_fft) for(int i=0; i<N; i++) a[i] /= N;
}
vector<ll> multiply(const vector<ll> &_a, const vector<ll> &_b){
  vector<cpx> a(_a.begin(),_a.end()), b(_b.begin(), _b.end());
  int N = 2; while(N < a.size() + b.size()) N <<= 1;
  a.resize(N); b.resize(N); FFT(a); FFT(b);
  for(int i=0; i<N; i++) a[i] *= b[i];
  vector<ll> ret(N); FFT(a, 1); // NTT : just return a
  for(int i=0; i<N; i++) ret[i] = llround(a[i].real());
  while(ret.size() > 1 && ret.back() == 0) ret.pop_back();
  return ret;
}

vector<int> G[101010];
int N, K, S[101010], U[101010];

int dfs(int v=1, int p=-1) {
    S[v]=1;
    for(int i:G[v]) if(i!=p && !U[i]) S[v]+=dfs(i,v);
    return S[v];
}

int getCentroid(int v, int sz=N, int p=-1) {
    for(int i:G[v]) {
        if(i!=p && !U[i] && S[i]*2>sz) return getCentroid(i,sz,v);
    }
    return v;
}

void calc(vector<ll> &h, int v, int p, int d=1) {
    h[d]++;
    for(int i:G[v]) if(i!=p && !U[i]) calc(h,i,v,d+1);
}

vector<int> vec;
void update(vector<ll> &s, vector<ll> &h, int v, int p, int d=1) {
    s[d]++, h[d]=0;
    vec.push_back(d);
    for(int i:G[v]) if(i!=p && !U[i]) update(s,h,i,v,d+1);
}

ll A[101010], SV[101010]={1,1};

void dnc(int v=1) {
    int sz;
    v=getCentroid(v, sz=dfs(v)), dfs(v);
    U[v]=1;

    vector<ll> s(sz+1), h(sz+1);
    for(int i:G[v]) if(!U[i]) {
        h.clear(), h.resize(S[i]+1);
        calc(h,i,v);
        s[0]=1;
        auto c=multiply(s,h);
        for(int j=0;j<c.size();j++) A[j]+=c[j];
        update(s,h,i,v);
    }

    for(int i:G[v]) if(!U[i]) dnc(i);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1,u,v;i<N;i++) {
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    dnc();

    for(int i=2;i*i<101010;i++) if(!SV[i]) for(int j=2*i;j<101010;j+=i) SV[j]=1;
    ll sum=0, tot=accumulate(A+1, A+N, 0LL);
    for(int i=2;i<=N;i++) if(!SV[i]) sum+=A[i];
    cout << fixed << setprecision(12) << (double)sum/tot << '\n';
    return 0;
}