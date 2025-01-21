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

constexpr int MOD=1e9+7;
int N, R, Q, D[303030];
vector<int> G[303030];

void dfs(int v, int p=-1) {
    for(int i:G[v]) if(i!=p) D[i]=D[v]+1, dfs(i,v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> R;
    for(int i=1,u,v;i<N;i++) cin >> u >> v, G[v].push_back(u), G[u].push_back(v);
    dfs(R);
    poly a(N+1);
    for(int i=1;i<=N;i++) if(i!=R && G[i].size()==1) a[D[i]]+=1;
    vector<ll> b = f(a);
    for(ll &i:b) i%=MOD;
    for(int i=1;i<b.size();i++) b[i]=(b[i]+b[i-1])%MOD;

    cin >> Q;
    for(int i=0,l,r;i<Q;i++) {
        cin >> l >> r;
        cout << (b[r]-b[l-1]+MOD)%MOD << '\n';
    }
    return 0;
}