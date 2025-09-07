#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz=1<<18;
struct {
    int T[sz<<1];
    void update(int v, int x) {
        v|=sz, T[v]=max(T[v],x);
        while(v>>=1) T[v]=max(T[v*2],T[v*2+1]);
    }
    int query(int l, int r) {
        int res=0;
        for(l|=sz,r|=sz ; l<=r ; l/=2,r/=2) {
            if(l&1) res=max(res,T[l++]);
            if(~r&1) res=max(res,T[r--]);
        }
        return res;
    }
} seg;

int N, K;
vector<int> A[10101], B[10101];

void sol(int tc) {
    cin >> N >> K;
    for(int i=1;i<=N*K;i++) {
        int x; cin >> x;
        A[x].push_back(i);
    }
    for(int i=1;i<=N*K;i++) {
        int x; cin >> x;
        B[x].push_back(i);
    }

    vector<pair<int,int>> vec;
    for(int i=1;i<=N;i++) {
        for(int j:A[i]) for(int k:B[i]) {
            vec.push_back({j,k});
        }
    }
    sort(vec.begin(),vec.end(),[](pair<int,int> a, pair<int,int> b){
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    int mx=0;
    for(auto [a,b]:vec) {
        int t = seg.query(0,b-1)+1;
        mx=max(mx,t);
        seg.update(b,t);
    }
    cout << mx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}