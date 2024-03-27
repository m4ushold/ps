#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Qry=tuple<int,int,int>;

constexpr int MOD=1e9+7;
int N, M, Q, A[202020];
ll V[202020][20], R[202020];

int mod(int a) { return ((a%M)+M)%M; }

void f(int l, int r, vector<Qry> &q) {
    if(l==r) {
        for(auto [s,e,i]:q) if(A[s]==0) R[i]=1;
        return ;
    }

    int m=l+r>>1;
    vector<Qry> lq, mq, rq;
    for(auto j:q) {
        auto [s,e,i]=j;
        if(e<=m) lq.push_back(j);
        else if(m+1<=s) rq.push_back(j);
        else mq.push_back(j);
    }

    for(int i=l;i<=r;i++) {
        for(int j=0;j<M;j++) V[i][j]=0;
        V[i][A[i]]=1;
    }
    
    for(int i=m-1;i>=l;i--) {
        for(int j=0;j<M;j++) V[i][j]=(V[i][j]+(V[i+1][j]+V[i+1][mod(j-A[i])])%MOD)%MOD;
    }
    
    for(int i=m+2;i<=r;i++) {
        for(int j=0;j<M;j++) V[i][j]=(V[i][j]+(V[i-1][j]+V[i-1][mod(j-A[i])])%MOD)%MOD;
    }

    for(auto [s,e,i]:mq) {
        R[i]=(V[s][0]+V[e][0])%MOD;
        for(int j=0;j<M;j++) R[i]=(R[i]+V[s][j]*V[e][mod(-j)])%MOD;
    }

    if(!lq.empty()) f(l,m,lq);
    if(!rq.empty()) f(m+1,r,rq);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i], A[i]=A[i]%M;
    cin >> Q;
    vector<Qry> q;
    for(int i=1,s,e;i<=Q;i++) cin >> s >> e, q.emplace_back(s,e,i);
    f(1,N,q);
    for(int i=1;i<=Q;i++) cout << (R[i]+1)%MOD << "\n";
    return 0;
}