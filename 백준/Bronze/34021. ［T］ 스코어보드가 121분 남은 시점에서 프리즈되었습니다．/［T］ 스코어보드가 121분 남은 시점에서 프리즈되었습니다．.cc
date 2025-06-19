#include <bits/stdc++.h>
using namespace std;

void sol() {
    int n,m,l; cin >> n >> m >> l;
    int t=l;
    for(int i=0,x;i<n;i++) {
        cin >> x;
        if(x>=0) t=max(t, m-x);
    }
    cout << "The scoreboard has been frozen with " << t << (t>1?" minutes":" minute") << " remaining.\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}