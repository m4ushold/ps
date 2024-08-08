#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void solve(){
    int n, k; cin >> n >> k;
    vector<int>nxt(n+1), A(n+1), idx(k+1);
    for(int s=1; s<=n; s++)cin >> A[s]; 

    for(int s=n; s>=1; s--){
        nxt[s] = idx[A[s]];
        idx[A[s]] = max(s, idx[A[s]]);
    }
    vector<int>in(k+1);
    vector<P>S;
    for(int s=1; s<=n; s++){
        if(in[A[s]])continue;
        while(S.size() && S.back().first > A[s] && nxt[S.back().second] > s){
            in[S.back().first] = 0;
            S.pop_back();
        }
        S.push_back({A[s], s});
        in[A[s]] = 1;
    }
    assert(S.size() == k);
    for(auto [v, i] : S)cout << v << " ";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    while(T--)solve();
}