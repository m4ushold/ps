#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct SegTree {
    const static int sz=1<<14;
    pair<int,int> T[sz<<1];
    void clear() {
        memset(T, 0, sizeof(T));
    }
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

int N, DP[1010101], P[1010101], A[1010101], B[1010101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        seg.clear();
        memset(B, 0, sizeof(B));
        cin >> N;
        vector<int> v(N);
        for(int i=1;i<=N;i++) cin >> A[i], v[i-1]=A[i];
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()), v.end());
        for(int i=1;i<=N;i++) A[i]=lower_bound(v.begin(),v.end(),A[i])-v.begin()+1;

        for(int i=1;i<=N;i++) {
            auto [mx,j]=seg.query(0,A[i]-1);
            DP[i]=mx+1, P[i]=j;
            seg.update(A[i],DP[i],i);
        }
        int i=max_element(DP,DP+N+1)-DP;
        cout << DP[i] << '\n';
        while(i) B[i]=1, i=P[i];
        for(int i=1;i<=N;i++) if(B[i]) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}