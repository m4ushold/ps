#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, Q, P[101010], S[101010], C[101010];
int Find(int v) {return v==P[v] ? v : P[v]=Find(P[v]);}
bool Union(int u, int v) {
    u=Find(u), v=Find(v);
    P[u]=v;
    S[v]+=S[u];
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++) P[i]=i, S[i]=1;
    vector<int> w;
    vector<tuple<int,int,int>> edge(N-1);
    for(auto &[a,b,c]:edge) cin >> a >> b >> c, w.push_back(c);
    sort(w.begin(),w.end());
    w.erase(unique(w.begin(),w.end()),w.end());
    for(auto &[a,b,c]:edge) c=lower_bound(w.begin(),w.end(),c)-w.begin()+1, swap(a,c);

    sort(edge.begin(),edge.end());
    for(auto [w,u,v]:edge) {
        C[w]+=S[Find(u)]*S[Find(v)];
        Union(u,v);
    }

    for(int i=1;i<=N;i++) {
        C[i]*=w[i-1];
        C[i]+=C[i-1];
    }
    for(int i=0,l,r;i<Q;i++) {
        cin >> l >> r;
        l=lower_bound(w.begin(),w.end(),l)-w.begin()+1;
        r=upper_bound(w.begin(),w.end(),r)-w.begin();
        cout << C[r]-C[l-1] << '\n';
    }

    return 0;
}