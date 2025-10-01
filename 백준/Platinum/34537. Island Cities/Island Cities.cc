#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, M, B;
vector<array<ll,6>> E;

int P[303030], S[303030], R[101010];
void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

bool chk(ll m) {
    priority_queue<array<ll,5>,vector<array<ll,5>>,greater<>> pq;
    for(auto [u,v,w,x,y,i]:E) {
        ll t = (m-w)/x;
        if(m-w <= 0) {
            pq.push({0,u,v,i,0});
            continue;
        }
        else if((m-w)%x) t++;
        pq.push({t*y,u,v,i,t});
    }
    init(N);
    ll sum=0;
    while(S[Find(1)] < N) {
        auto [c,u,v,i,t] = pq.top(); pq.pop();
        if(Union(u,v)) sum+=c, R[i]=t;
    }
    return sum <= B;
}

void sol(int tc) {
    cin >> N >> M >> B;
    for(int i=0;i<M;i++) {
        E.emplace_back();
        for(int j=0;j<5;j++) cin >> E[i][j];
        E[i][5]=i;
    }
    ll l=0, r=1e12;
    while(l<r) {
        ll m=l+r+1>>1;
        if(chk(m)) l=m;
        else r=m-1;
    }
    
    for(int i=0;i<M;i++) R[i]=0;
    chk(l);
    cout << l << "\n";
    for(int i=0;i<M;i++) cout << R[i] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}