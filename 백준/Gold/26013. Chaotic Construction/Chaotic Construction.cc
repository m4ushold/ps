#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const int tN = 1<<17;
int tree[tN];
void update(int i,int k){
    for(; i<tN; i += i & -i)tree[i] += k;
}
int sum(int i){
    int ret = 0;
    for(; i; i -= i & -i)ret += tree[i];
    return ret;
}
int query(int l,int r){return sum(r) - sum(l-1);}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, Q; cin >> n >> Q;
    while(Q--){
        char op; cin >> op;
        if(op == '?'){
            int l, r; cin >> l >> r;
            if(l > r)swap(l, r);
            if(query(l, r) && sum(l) + query(r, n))cout << "impossible\n";
            else cout << "possible\n";
        }else if(op == '-'){
            int i; cin >> i;
            update(i, 1);
        }else{
            int i; cin >> i;
            update(i, -1);
        }
    }
}