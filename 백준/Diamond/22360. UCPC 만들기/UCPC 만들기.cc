#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<18;
ll N, R, A[sz], U[sz], S[sz];
vector<int> G[sz];
map<pair<int,int>,int> M;

// u p c
pair<int,int> P[] = {{1,1}, {-1,1}, {0,-1}};

int dfs(int v=1, int p=-1) {
    S[v]=1;
    for(auto i:G[v]) if(i!=p && !U[i]) S[v]+=dfs(i,v);
    return S[v];
}

int getCentroid(int v, int sz, int p=-1) {
    for(auto i:G[v]) {
        if(i!=p && !U[i] && S[i]*2>sz) return getCentroid(i, sz, v);
    }
    return v;
}

void upd(int v, int p, pair<int,int> t) {
    t.first += P[A[v]].first, t.second += P[A[v]].second;
    M[t]++;
    for(auto i:G[v]) if(i!=p && !U[i]) upd(i,v,t);
}

void calc(int v, int p, pair<int,int> t) {
    t.first += P[A[v]].first, t.second += P[A[v]].second;
    R += M[{-t.first,-t.second}];
    for(auto i:G[v]) if(i!=p && !U[i]) calc(i,v,t);
}

void dnc(int v=1) {
    v = getCentroid(v, dfs(v)), U[v] = 1, M.clear();

    pair<int,int> t=P[A[v]];
    M[t]++;

    for(auto i:G[v]) if(!U[i]) calc(i,v,{0,0}), upd(i,v,t);
    for(auto i:G[v]) if(!U[i]) dnc(i);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> N >> s;
    for(int i=0;i<N;i++) {
        if(s[i] == 'U') A[i+1] = 0;
        else if(s[i] == 'P') A[i+1] = 1;
        else A[i+1] = 2;
    }
    for(int i=1,u,v;i<N;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    dnc();
    cout << R;
    return 0;
}