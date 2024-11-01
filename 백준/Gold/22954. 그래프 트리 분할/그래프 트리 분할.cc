#include <bits/stdc++.h>
using namespace std;

int N, M, P[101010], S[101010], I[101010];
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    if(N<=2) return cout << -1, 0;
    for(int i=1;i<=N;i++) P[i]=i,S[i]=1;
    vector<tuple<int,int,int>> v;
    for(int i=0,s,e;i<M;i++) {
        cin >> s >> e;
        if(Union(s,e)) v.push_back({i+1,s,e}), I[s]++, I[e]++;
    }
    int cnt=0;
    vector<int> a;
    for(int i=1;i<=N;i++) if(i==P[i]) cnt++, a.push_back(i);
    if(cnt>2) return cout << -1, 0;
    else if(cnt==2) {
        if(S[a[0]] == S[a[1]]) return cout << -1, 0;
        cout << S[a[0]] << ' ' << S[a[1]] << '\n';
        for(int i=1;i<=N;i++) if(Find(i)==a[0]) cout << i << ' ';
        cout << '\n';
        for(auto [i,s,e]:v) if(Find(s)==a[0]) cout << i << ' ';
        cout << '\n';
        for(int i=1;i<=N;i++) if(Find(i)==a[1]) cout << i << ' ';
        cout << '\n';
        for(auto [i,s,e]:v) if(Find(s)==a[1]) cout << i << ' ';
    } else if(cnt==1) {
        cout << "1 " << N-1 << '\n';
        int t;
        for(int i=1;i<=N;i++) if(I[i]==1) {t=i; break;}
        cout << t << "\n\n";
        for(int i=1;i<=N;i++) if(i!=t) cout << i << ' ';
        cout << '\n';
        for(auto [i,s,e]:v) if(s!=t && e!=t) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}