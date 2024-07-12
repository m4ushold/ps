#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void solve(){
    int n; cin >> n;
    vector<int>A(n), B(n-1), cnt(1001);
    for(int &i : A)cin >> i;
    for(int &i : B)cin >> i, cnt[i]++;
    for(int i : A)cnt[i]--;
    for(int s=0; s<1001; s++)if(cnt[s])cout << s << "\n";
    
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while(T--)solve();
}