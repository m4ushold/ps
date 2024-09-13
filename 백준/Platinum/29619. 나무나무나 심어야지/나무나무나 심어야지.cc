#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct LazySeg {
    const static int sz=1<<18;
    int T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]=x;
        while(i>>=1) T[i]=T[i*2]+T[i*2+1];
    }
    int qry(int l, int r) {
        int ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret+=T[l++];
            if(~r&1) ret+=T[r--];
        }
        return ret;
    }
} seg;

int N, M, W[202020], IN[202020], OUT[202020];
vector<int> G[202020];

void dfs(int v=1, int p=-1) {
    static int pv=0;
    IN[v]=++pv;
    for(int i:G[v]) if(i!=p) dfs(i,v);
    OUT[v]=pv;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1,v;i<=N;i++) {
        cin >> v;
        if(v>0) G[v].push_back(i);
    }
    for(int i=1;i<=N;i++) cin >> W[i];

    vector<tuple<int,int,int,int>> v;

    int mx=N;
    for(int q=0,a,i,j,w;q<M;q++) {
        cin >> a >> i;
        if(a==1) {
            cin >> j >> w;
            G[i].push_back(j);
            W[j]=w;
            v.push_back({a,i,j,w});
            mx=max(mx,j);
        } else v.push_back({a,i,0,0});
    }
    dfs();
    for(int i=1;i<=mx;i++) seg.upd(IN[i],W[i]);
    reverse(v.begin(),v.end());

    vector<int> dap;
    for(auto [q,i,j,w]:v) {
        if(q==1) seg.upd(IN[j], 0);
        else dap.push_back(seg.qry(IN[i], OUT[i]));
    }
    reverse(dap.begin(),dap.end());
    for(int i:dap) cout << (i?i:-1) << '\n';
    return 0;
}