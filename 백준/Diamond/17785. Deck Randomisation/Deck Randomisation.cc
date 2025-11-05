#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll mod(ll a, ll b) { return ((a%b) + b) % b; }

tuple<ll,ll,ll> ext_gcd(ll a, ll b){
    if(b == 0) return {a, 1, 0};
    auto [g,x,y] = ext_gcd(b, a % b);
    return {g, y, x - a/b * y};
}
pair<ll,ll> crt(ll a1, ll m1, ll a2, ll m2){
    ll g = gcd(m1, m2), m = lcm(m1, m2);
    if((a2 - a1) % g) return {-1, -1};
    ll mul = mod((a2-a1)/g, m2);
    ll x = mod(get<1>(ext_gcd(m1, m2)), m2) * mul % m2;
    return { (a1 + x * m1) % m, m };
}
pair<ll,ll> crt(const vector<ll> &a, const vector<ll> &m){
    ll ra = a[0], rm = m[0];
    for(int i=1; i<m.size(); i++){
        auto [aa,mm] = crt(ra, rm, a[i], m[i]);
        if(mm == -1) return {-1, -1}; 
        else tie(ra,rm) = tie(aa,mm);
    }
    return {ra, rm};
}

int N, A[101010], B[101010], C[101010], D[101010];

int P[303030], S[303030];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

void print(ll ans) {
    if(ans > 1'000'000'000'000) cout << "huge";
    else cout << ans;
    exit(0);
}

void sol(int tc) {
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int j=1;j<=N;j++) cin >> B[j];
    init(N);
    for(int i=1;i<=N;i++) C[i] = B[A[i]], Union(i,C[i]);
    __int128_t even=1;
    for(int i=1;i<=N;i++) if(i==Find(i)) {
        even = lcm<__int128_t>(even, S[i]);
        if(even > 1e12) {even = 1e13; break;}
    }
    even <<= 1;
    __int128_t odd=1e13;

    vector<ll> a,m;
    for(int i=1;i<=N;i++) if(i == Find(i)) {
        vector<int> t, tt;
        int y=i;
        do {
            t.push_back(y);
            tt.push_back(A[y]);
            y=C[y];
        } while(y != i);
        m.push_back(t.size());

        ll x = find(all(t),tt.front())-t.begin();

        if(x == t.size() || t.size() != tt.size()) {
            print(even);
        }

        for(int j=0;j<t.size();j++) if(t[(j+x)%t.size()] != tt[j]) {
            print(even);
        }

        x = mod(-x,m.back());
        a.push_back(x);
    }

    auto [ra,rm] = crt(a,m);
    if(ra >= 0) odd = ra*2+1;

    print(min(even,odd));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}