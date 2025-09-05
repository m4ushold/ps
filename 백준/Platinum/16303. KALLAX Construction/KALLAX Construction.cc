#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int B, N, D[2020];
vector<int> A[22];

vector<pair<int,int>> ns(vector<pair<int,int>> v, int idx) {
    fill(D, D+2020, 1e9);
    D[0]=0;
    for(auto [a,b]:v) {
        for(int j=0;j<2020;j++) if(j>=a) {
            D[j] = min(D[j], D[j-a]+b);
        }
    }
    vector<pair<int,int>> res;
    for(int i:A[idx]) {
        int j=i;
        while(D[j] == 1e9) j++;
        res.push_back({i,D[j]});
    }
    return res;
}

void sol(int tc) {
    cin >> B >> N;
    for(int i=1;i<=N;i++) {
        int n; cin >> n;
        while(n--) {
            int x; cin >> x;
            A[i].push_back(x);
        }
        sort(A[i].begin(),A[i].end(),greater<>());
    }
    fill(D, D+2020, 1e9);
    D[0]=0;
    vector<pair<int,int>> all, prv;
    for(int i:A[1]) prv.push_back({i,i}), all.push_back({i,i});
    sort(prv.begin(),prv.end());
    for(int i=1;i<=N;i++) {
        prv = ns(prv, i);
        for(auto i:prv) all.push_back(i);
    }
    int res=1e9;
    for(auto [a,b]:all) {
        if(b>=B) res=min(res,a);
    }
    if(res == 1e9) cout << "impossible";
    else cout << res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}