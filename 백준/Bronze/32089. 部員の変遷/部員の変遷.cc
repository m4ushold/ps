#include <bits/stdc++.h>
using namespace std;

void sol(int n) {
    vector<int> a(n+1);
    int sum=0, mx=0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        sum+=a[i]-a[max(i-3,0)];
        mx=max(mx,sum);
    }
    cout << mx << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    while(cin >> t && t) sol(t);
    return 0;
}