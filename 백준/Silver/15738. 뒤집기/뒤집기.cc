#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k; cin >> n >> k >> m;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    for(int i=0,x;i<m;i++) {
        cin >> x;
        if(x>0 && k<=x) k=x-k+1;
        if(x<0 && n+x<k) k = n + x + (n-k)+1;
    }
    cout << k;
    return 0;
}