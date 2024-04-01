#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    const static int sz=1<<16;
    pair<int,int> T[sz<<1];
    void update(int v, int x, int i) {
        v|=sz, T[v]=max(T[v],{x,i});
        while(v>>=1) T[v]=max(T[v*2],T[v*2+1]);
    }
    pair<int,int> query(int l, int r) {
        pair<int,int> res;
        for(l|=sz,r|=sz ; l<=r ; l/=2,r/=2) {
            if(l&1) res=max(res,T[l++]);
            if(~r&1) res=max(res,T[r--]);
        }
        return res;
    }
} seg;

int N, DP[50505], P[50505], A[50505];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    vector<int> v(N);
    for(int i=1;i<=N;i++) cin >> A[i], v[i-1]=A[i];
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    for(int i=1;i<=N;i++) A[i]=lower_bound(v.begin(),v.end(),A[i])-v.begin()+1;

    for(int i=1;i<=N;i++) {
        auto [mx,j]=seg.query(A[i]+1,2020);
        DP[i]=mx+1, P[i]=j;
        seg.update(A[i],DP[i],i);
    }
    cout << N-*max_element(DP,DP+N+1);
    return 0;
}