#include <bits/stdc++.h>
using namespace std;

vector<int> G[101010];
const int INF=1e9;
int N, R=INF, S[101010], U[101010], V[101010], C[101010];

int dfs(int v=1, int p=-1) {
    S[v]=1;
    for(auto i:G[v]) if(i!=p && !U[i]) S[v]+=dfs(i,v);
    return S[v];
}

int getCentroid(int v, int sz, int p=-1) {
    for(auto i:G[v]) {
        if(i!=p && !U[i] && S[i]*2>sz) return getCentroid(i,sz,v);
    }
    return v;
}

vector<int> vec;
void upd(int v, int p, int d=1) {
    V[C[v]]=min(V[C[v]], d), vec.push_back(C[v]);
    for(auto i:G[v]) if(i!=p && !U[i]) upd(i,v,d+1);
}

void calc(int v, int p, int d=1) {
    R=min(R, V[C[v]]+d);
    for(auto i:G[v]) if(i!=p && !U[i]) calc(i,v,d+1);
}

void dnc(int v=1) {
    // 1. v에 현재 서브 트리의 Centroid를 구해서 대입
    v=getCentroid(v, dfs(v));
    U[v]=1, V[C[v]]=0, vec.push_back(C[v]);

    // 2. v를 지나는 모든 경로에 대해 길이가 k인 경로 처리
    for(auto i:G[v]) if(!U[i]) calc(i,v), upd(i,v);
    for(int i:vec) V[i]=INF;
    vec.clear();

    // 3. v를 트리에서 제거, v와 인접한 모든 노드 i에 대해 dnc(i)를 호출
    for(auto i:G[v]) if(!U[i]) dnc(i);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> C[i];
    for(int i=1,u,v;i<N;i++) {
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    for(int i=1;i<=N;i++) V[i]=INF;
    dnc();
    cout << R;
    return 0;
}