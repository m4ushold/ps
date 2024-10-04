#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int tot=0;
    queue<pair<int,int>> q;
    for(int i=0,a;i<n;i++) cin >> a, tot+=a, q.push({a,i});
    vector<int> v(n);
    for(int i=1;i<=tot;i++) {
        auto [x,j] = q.front();
        if(x>1) q.push({x-1,j});
        else v[j]=i;
        q.pop();
    }
    for(int i:v) cout << i << ' ';
    return 0;
}