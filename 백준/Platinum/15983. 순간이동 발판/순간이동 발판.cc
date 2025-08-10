#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod(ll a, ll b) { return ((a%b) + b) % b; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

tuple<ll,ll,ll> ext_gcd(ll a, ll b){
    if(b == 0) return {a, 1, 0};
    auto [g,x,y] = ext_gcd(b, a % b);
    return {g, y, x - a/b * y};
}
ll inv(ll a, ll m){
    auto [g,x,y] = ext_gcd(a, m);
    return g == 1 ? mod(x, m) : -1;
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

int N, T, D[111];
vector<array<ll,3>> G[111], A[1010101];

void dijkstra(int s) {
    for(int i=1;i<111;i++) D[i]=1e9;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<>> pq;
    D[s]=0; pq.emplace(0,s);
    while(!pq.empty()) {
        auto [c,v] = pq.top(); pq.pop();
        for(auto [i,x,m]:G[v]) {
            ll a = (x-D[v]%m+m)%m;
            if(D[i]>D[v]+a){
                D[i]=D[v]+a;
                pq.emplace(D[i], i);
            }
        }
    }
}

void sol(int tc) {
    cin >> N >> T;
    int ss=0,ee=-1;
    for(int i=1;i<=N;i++) {
        int k; cin >> k;
        vector<int> v(k);
        for(int j=0;j<k;j++) {
            cin >> v[j];
            if(v[j]==0) ss=i;
            if(v[j]==T) ee=i;
            A[v[j]].push_back({j,k,i});
        }
    }
    for(int i=0;i<1010101;i++) {
        if(A[i].size()==2) {
            auto [a,b,c]=A[i][0];
            auto [d,e,f]=A[i][1];
            auto [x,m] = crt(a,b,d,e);
            if(x!=-1) {
                G[c].push_back({f,x,m});
                G[f].push_back({c,x,m});
            }
        }
    }
    if(ee==-1) {
        cout << -1;
        return;
    }
    auto [a,b,c] = A[T][0];
    G[ee].push_back({101,a,b});

    dijkstra(ss);
    int ans = D[101];

    if(ans >= 1e9) cout << -1;
    else cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}