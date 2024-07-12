#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
ll gcd(ll a,ll b){return b ? a : gcd(b, a%b);}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}
vector<ll>ans;
void solve(){
    int y, t1, t2; cin >> y >> t1 >> t2;
    ans.push_back(y + lcm(t1, t2));
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; cin >> T;
    while(T--)solve();
    cout << *min_element(all(ans));
}