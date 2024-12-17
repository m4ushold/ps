#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) for(int j=4,a;j>=0;j--) cin >> a, i|=a<<j;
    int mx=0, dap=3;
    for(int i=1;i<32;i++) if(__popcount(i) == 2) {
        int cnt=0;
        for(int j:v) if(__popcount(i&j) == 2) cnt++;
        if(mx < cnt) mx=cnt, dap=i;
    }
    cout << mx << '\n';
    for(int i=4;i>=0;i--) cout << bitset<5>(dap)[i] << ' ';
    return 0;
}