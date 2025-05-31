#include <bits/stdc++.h>
using namespace std;
 
int S[5050], F[5050][5050];
 
vector<int> ncr(int n, int r) {
    vector<int> v(5050);
    for(int i=0;i<5050;i++) v[i] = F[n][i] - F[r][i] - F[n-r][i];
    return v;
}
 
void sol() {
    int a,b,c,d; cin >> a >> b >> c >> d;
    vector<int> u = ncr(a,b), v = ncr(c,d);
    for(int i=0;i<u.size();i++) if(u[i] && v[i]) {
        cout << "0\n";
        return;
    }
    cout << "1\n";
}
 
vector<int> slow_factorize(int n) {
    vector<int> res;
    for(int i=2;i*i<=n;i++) while(n%i == 0) res.push_back(i), n/=i;
    if(n>1) res.push_back(n);
    return res;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=1;i<=5000;i++) {
        auto v = slow_factorize(i);
        for(int j:v) F[i][j]++;
        for(int j=2;j<=5000;j++) F[i][j]+=F[i-1][j];
    }
    
    int t; cin >> t;
    while(t--) sol();
    return 0;
}