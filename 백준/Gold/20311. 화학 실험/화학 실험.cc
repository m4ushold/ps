#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

void sol(int tc) {
    int n,k; cin >> n >> k;
    priority_queue<pll> pq;
    for(int i=0,c;i<k;i++) {
        cin >> c;
        pq.push({c,i+1});
    }

    vector<int> v;
    while(pq.size()) {
        if(pq.size() == 1) {
            if(pq.top().first > 1) {
                cout << -1;
                return;
            } else {
                v.push_back(pq.top().second);
                break;
            }
        } else {
            auto [x,i]=pq.top(); pq.pop();
            auto [y,j]=pq.top(); pq.pop();
            v.push_back(i), v.push_back(j);
            if(--x) pq.push({x,i});
            if(--y) pq.push({y,j});
        }
    }
    for(int i:v) cout << i << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}