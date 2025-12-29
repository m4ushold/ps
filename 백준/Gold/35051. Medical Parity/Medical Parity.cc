#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int D[1010101][2];

void sol(int tc) {
    string x,y; cin >> x >> y;
    int n = x.size();
    D[0][0] = (y[0] != '0') + (x[0] != '0');
    D[0][1] = (y[0] != '1') + (x[0] != '1');

    for(int i=1;i<n;i++) {
        D[i][0] = (y[i]!='0') + min(D[i-1][0] + (x[i]!='0'), D[i-1][1] + (x[i]!='1'));
        D[i][1] = (y[i]!='1') + min(D[i-1][0] + (x[i]!='1'), D[i-1][1] + (x[i]!='0'));
    }
    cout << min(D[n-1][0], D[n-1][1]) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}