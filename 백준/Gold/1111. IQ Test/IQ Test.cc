#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if(n==1) return cout << 'A', 0;
    else if(n==2) {
        int a,b; cin >> a >> b;
        if(a==b) cout << a;
        else cout << 'A';
        return 0;
    }

    vector<int> v(n);
    for(int &i:v) cin >> i;
    int a,b;
    if(v[0]==v[1]) a=1, b=0;
    else a = (v[2]-v[1])/(v[1]-v[0]), b = v[1]-v[0]*a;
    for(int i=0;i<n-1;i++) {
        if(v[i+1]!=v[i]*a+b) return cout << 'B', 0;
    }
    cout << v[n-1]*a+b;
    return 0;
}