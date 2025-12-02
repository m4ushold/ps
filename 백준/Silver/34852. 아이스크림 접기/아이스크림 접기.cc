#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
 
double rad(double t) {
    return acos(-1)*t/180;
}
 
void sol(int tc) {
    double n; cin >> n;
    double a = n-n/sqrt(3);
    cout << fixed << setprecision(12) << a/sqrt(2)/cos(rad(15))*a*sin(rad(60));
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}