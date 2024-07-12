#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void solve(){
    vector<P>A(4);
    for(auto &[x, y] : A)cin >> x >> y;
    auto len = [&](P a,P b){
        ll dx = a.first - b.first, dy = a.second - b.second;
        return dx*dx + dy*dy;
    };
    vector<ll>ans;
    ans.push_back(len(A[0], A[1]));
    ans.push_back(len(A[2], A[3]));
    cout << fixed; cout.precision(15);
    cout << sqrtl(*max_element(all(ans)));
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    while(T--)solve();
}