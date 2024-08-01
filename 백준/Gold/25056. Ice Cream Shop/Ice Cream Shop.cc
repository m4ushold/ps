#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void solve(){
    int n, m; cin >> n >> m;
    vector<ll>A(n+1), S(n+1); 
    for(int s=1; s<=n; s++)cin >> A[s], S[s] = S[s-1] + A[s];
    vector<int>B(m); for(int &i : B)cin >> i;
    sort(all(B));
    ll ans = 0, now = 0;
    if(B[0])ans = S[min(B[0]/100 + 1, n)];
    for(int s=0; s+1<m; s++){
        int L = (B[s] / 100 + (B[s] % 100 > 0)) * 100, R = B[s+1] / 100 * 100;
        while(L <= R && L + L - B[s] <= R + R - B[s+1])R -= 100;
        for(int e=L; e<B[s+1]; e+=100){
            if(e == B[s])continue;
            while(R <= B[s+1] && e + e - B[s] > R + R - B[s+1])R += 100;
            R -= 100;
            if(R/100 + 1 <= n && e <= R)ans = max(ans, S[R/100 + 1] - S[e/100]);
        }
    }
    int lst = B.back() / 100 + 1;
    if(lst < n)ans = max(ans, S[n] - S[lst]);
    cout << ans << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    while(T--)solve();
}