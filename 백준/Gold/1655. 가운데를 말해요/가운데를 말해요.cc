#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

void sol(int tc) {
    int n; cin >> n;
    priority_queue<int,vector<int>,greater<>> mn;
    priority_queue<int> mx;
    for(int i=0,x;i<n;i++) {
        cin >> x;
        if(mx.size() == mn.size()) mx.push(x);
        else mn.push(x);
        while(i && mx.top() > mn.top()) {
            int x = mx.top(), y = mn.top();
            mx.pop(), mn.pop();
            mn.push(x), mx.push(y);
        }
        cout << mx.top() << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}