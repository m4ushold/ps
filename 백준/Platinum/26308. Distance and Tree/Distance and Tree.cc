#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, R, A[101010], B[101010];
vector<int> D[101010];

constexpr int sz=1<<17;
struct Seg {
    ll T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]=x;
        while(i>>=1) T[i]=min(T[i*2],T[i*2+1]);
    }
    ll qry(int l, int r) {
        ll res=1e9;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) res=min(res,T[l++]);
            if(~r&1) res=min(res,T[r--]);
        }
        return res;
    }
} seg;

void sol(int tc) {
    cin >> N;
    int cnt=0;
    for(int i=0;i<N;i++) {
        cin >> A[i], cnt+=!A[i];
        if(A[i]==0) R=i;
    }
    if(cnt!=1) {
        cout << -1;
        return;
    }
    for(int i=0;i<N;i++) B[i]=A[(i+R)%N], seg.upd(i,B[i]);

    for(int i=0;i<N;i++) D[B[i]].push_back(i);
    vector<pair<int,int>> edges;
    for(int i=1;i<N;i++) {
        if(D[B[i]-1].empty()) {
            cout << -1;
            return;
        }

        int a = lower_bound(D[B[i]-1].begin(),D[B[i]-1].end(),i) - D[B[i]-1].begin()-1,b=a+1;
        int pp=-1;
        for(int p:{a,b}) {
            if(p<0 || p>=D[B[i]-1].size()) continue;
            int x=D[B[i]-1][p], cnt=0;
            if(x < i) cnt=seg.qry(x+1,i);
            else cnt=seg.qry(i,x-1);
            if(cnt >= B[i]-1) pp=x;
        }
        if(pp==-1) {
            cout << -1;
            return;
        }
        edges.push_back({pp,i});
    }

    for(auto [u,v]:edges) {
        cout << (R+u)%N+1 << ' ' << (R+v)%N+1 << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}