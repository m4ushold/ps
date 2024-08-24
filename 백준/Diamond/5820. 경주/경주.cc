#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> G[202020];
int N, K, R=INT_MAX/4, S[202020], U[202020], V[1010101];

int dfs(int v=1, int p=-1) {
    S[v]=1;
    for(auto [i,w]:G[v]) if(i!=p && !U[i]) S[v]+=dfs(i,v);
    return S[v];
}

int getCentroid(int v, int sz=N, int p=-1) {
    for(auto [i,w]:G[v]) {
        if(i!=p && !U[i] && S[i]*2>sz) return getCentroid(i,sz,v);
    }
    return v;
}

vector<int> vec;
void upd(int v, int p=-1, int w=0, int d=1) {
    if(w > K) return;
    V[w]=min(V[w],d), vec.push_back(w);
    for(auto [i,ww]:G[v]) if(i!=p && !U[i]) upd(i,v,w+ww,d+1);
}

void calc(int v, int p=-1, int w=0, int d=1) {
    if(w > K) return;
    R=min(R, V[K-w]+d);
    for(auto [i,ww]:G[v]) if(i!=p && !U[i]) calc(i,v,w+ww,d+1);
}

void dnc(int v=1) {
    for(int i:vec) V[i]=INT_MAX/4;
    vec.clear();

    // 1. v에 현재 서브 트리의 Centroid를 구해서 대입
    v=getCentroid(v, dfs(v));

    // 2. v를 지나는 모든 경로에 대해 길이가 k인 경로 처리
    for(auto [i,w]:G[v]) if(!U[i]) calc(i,v,w), upd(i,v,w);

    // 3. v를 트리에서 제거, v와 인접한 모든 노드 i에 대해 dnc(i)를 호출
    U[v]=1;
    for(auto [i,w]:G[v]) if(!U[i]) dnc(i);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1,a,b,w;i<N;i++) cin >> a >> b >> w, ++a, ++b, G[a].push_back({b,w}), G[b].push_back({a,w});
    for(int i=1;i<=N;i++) V[i]=INT_MAX/4;
    dnc();
    cout << (R==INT_MAX/4 ? -1 : R);
    return 0;
}