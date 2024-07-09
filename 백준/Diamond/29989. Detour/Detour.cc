#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

int N, M, C[303], D[303], A[303][303];
vector<pair<int,int>> G[303], E;

void sp(int ban) {
    for(int it=1;it<=N;it++) {
        int v=-1;
        for(int i=1;i<=N;i++) {
            if(C[i]) continue;
            if(v==-1 || D[v]>D[i]) v=i;
        }
        if(v==-1) break;
        C[v]=1;
        for(auto [i,w]:G[v]) if(i!=ban && !C[i]) D[i]=min(D[i],D[v]+w);
    }
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0,s,e,w;i<M;i++) {
        cin >> s >> e >> w;
        G[s].emplace_back(e,w), G[e].push_back({s,w});
        E.push_back({s,e});
    }
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) A[i][j]=1e9;

    for(int i=1;i<N;i++) {
        for(int b=0;b<9;b++) {
            for(int i=1;i<=N;i++) D[i]=1e9, C[i]=0;
            C[i]=1;
            for(auto [v,w]:G[i]) if(v>>b&1) D[v]=w;
            sp(i);
            for(auto [v,w]:G[i]) if(~v>>b&1) A[i][v]=min(A[i][v], D[v]);

            for(int i=1;i<=N;i++) D[i]=1e9, C[i]=0;
            C[i]=1;
            for(auto [v,w]:G[i]) if(~v>>b&1) D[v]=w;
            sp(i);
            for(auto [v,w]:G[i]) if(v>>b&1) A[i][v]=min(A[i][v], D[v]);
        }
    }

    for(auto [i,j]:E) {
        if(i>j) swap(i,j);
        cout << (A[i][j]==(int)1e9 ? -1 : A[i][j]) << '\n';
    }
    return 0;
}