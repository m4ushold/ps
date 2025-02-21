#include<bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(v) v.begin(),v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end());

using namespace std;
using ll = long long;

// PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>;

// rope
#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension

const int sz=1<<19;
struct Seg {
    int T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]+=x;
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
    int kth(int k) {
        int i=1;
        while(i<sz) {
            if(k <= T[i*2]) i*=2;
            else k-=T[i*2], i=i*2+1;
        }
        return i^sz;
    }
} seg;

ll N, M, S[101010], A[101010];

void sol(int tc) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    vector<ll> v;
    vector<array<ll,3>> q;
    for(int i=1;i<=N;i++) cin >> S[i], v.push_back(A[i]=S[i]);

    for(ll i=1,op,j,x,y,l,r,t;i<=M;i++) {
        cin >> op;
        if(op==1) cin >> j >> x, v.push_back(A[j]), v.push_back(A[j]+=x), q.push_back({op,j,x});
        else if(op==2) cin >> j >> y, v.push_back(A[j]), v.push_back(A[j]-=y), q.push_back({op,j,y});
        else if(op==3) cin >> l >> r, v.push_back(l), v.push_back(r), q.push_back({op,l,r});
        else if(op==4) cin >> t, q.push_back({op,t,0});
    }
    compress(v);

    for(int i=1;i<=N;i++) {
        A[i]=S[i];
        seg.upd(lower_bound(all(v), A[i])-v.begin(), 1);
    }

    for(auto [op,x,y]:q) {
        if(op == 1) {
            seg.upd(lower_bound(all(v), A[x]) - v.begin(), -1);
            seg.upd(lower_bound(all(v), A[x]+=y) - v.begin(), 1);
        } else if(op == 2) {
            seg.upd(lower_bound(all(v), A[x]) - v.begin(), -1);
            seg.upd(lower_bound(all(v), A[x]-=y) - v.begin(), 1);
        } else if(op == 3) {
            x = lower_bound(all(v), x) - v.begin(), y = lower_bound(all(v), y) - v.begin();
            cout << seg.qry(x,y) << '\n';
        } else {
            cout << v[seg.kth(N-x+1)] << '\n';
        }
    }
}

int main() {
    fastio;
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}