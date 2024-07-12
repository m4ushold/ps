#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const int tN = 1<<20;
const ll oo = 1e15;
struct SegmentTree{
    ll tree[tN];
    SegmentTree(){
        fill(tree, tree+tN, -oo);
    }
    void update(int i,ll k){
        i += tN/2 - 1;
        tree[i] = k;
        for(int s=i>>1; s>0; s>>=1)tree[s] = max(tree[s << 1], tree[s << 1 | 1]);
    }
    ll query(int l,int r,int n =1,int nl =1,int nr = tN/2){
        if(l > nr || r < nl)return -oo;
        if(l <= nl && nr <= r)return tree[n];
        int m = (nl + nr) >> 1;
        return max(query(l, r, n << 1, nl, m), query(l, r, n << 1 | 1, m+1, nr));
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll C; cin >> C;
    vector<P>A(n+1); 
    for(int s=1; s<=n; s++){
        int k; cin >> k;
        A[s] = {k, s};
    }
    sort(all(A));
    vector<ll>ans(n+1);
    SegmentTree ST1;
    for(int s=1; s<=n; s++){
        auto [v, i] = A[s];
        ll mx = ST1.query(1, i-1);
        if(mx > -oo){
            ans[i] = max(ans[i], mx + v - C*i);
        }
        ST1.update(i, -v + C*i);
    }
    SegmentTree ST2;
    A[0] = {oo, oo};
    sort(all(A), greater<P>());
    for(int s=1; s<=n; s++){
        auto [v, i] = A[s];
        ll mx = ST2.query(1, i-1);
        if(mx > -oo){
            ans[i] = max(ans[i], mx - C*i - v);
        }
        ST2.update(i, v + C*i);
    }
    for(int s=1; s<=n; s++)cout << ans[s] << " ";
}