#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M, F, P[555], S[555];
vector<tuple<int,int,double,double>> E;

void init(int n) { for(int i=1;i<=n;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

bool chk(double m) {
    sort(E.begin(),E.end(),[&m](auto &a, auto &b){
        return get<2>(a)+get<3>(a)*m < get<2>(b)+get<3>(b)*m;
    });
    init(N);
    double s=0;
    for(auto [i,j,c,t]:E) if(Union(i,j)) s+=c+m*t;
    return s<=F;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> F;
    E.resize(M);
    for(auto &[a,b,c,d]:E) cin >> a >> b >> c >> d;

    double l=0, r=2e9;
    for(int i=0;i<200;i++) {
        double m=(l+r)/2;
        if(chk(m)) l=m;
        else r=m;
    }
    cout << fixed << setprecision(4) << l;
    return 0;
}