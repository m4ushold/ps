#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

void sol(int tc) {
    int n,m; cin >> n >> m;
    priority_queue<int> a, b;
    for(int i=0,x;i<n;i++) cin >> x, a.push(x);
    for(int i=0,x;i<m;i++) cin >> x, b.push(x);
    int t=1;
    while(a.size() && b.size()) {
        if(t&1) { // alice
            int x = b.top(); b.pop();
            x-=a.top();
            if(x>0) b.push(x);
        } else { // bob
            int x = a.top(); a.pop();
            x-=b.top();
            if(x>0) a.push(x);
        }
        t^=1;
    }
    if(a.size()) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}