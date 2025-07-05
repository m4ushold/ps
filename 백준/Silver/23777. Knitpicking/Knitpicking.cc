#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    map<string,array<int,3>> m;
    int n; cin >> n;
    int tot=0, mx=0;
    for(int i=0;i<n;i++) {
        string a,b; int c; cin >> a >> b >> c;
        auto &arr = m[a];
        if(b == "left") arr[0]+=c;
        else if(b == "right") arr[1]+=c;
        else arr[2]+=c;
        tot+=c;
    }
    for(auto [i,j]:m) {
        mx += max<int>({j[0], j[1], (j[2]>0)});
    }
    if(tot == mx) cout << "impossible";
    else cout << mx+1;
    return 0;
}