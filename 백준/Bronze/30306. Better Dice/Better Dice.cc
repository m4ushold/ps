#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int &i:a) cin >> i;
    for(int &i:b) cin >> i;
    int aa=0,bb=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        if(a[i]>b[j]) ++aa;
        if(b[j]>a[i]) ++bb;
    }
    if(aa==bb) cout << "tie";
    else if(aa>bb) cout << "first";
    else cout << "second";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}