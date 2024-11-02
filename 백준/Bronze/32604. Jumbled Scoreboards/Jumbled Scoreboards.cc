#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i] >> b[i];
    for(int i=1;i<n;i++) if(a[i-1]>a[i]) return cout << "no", 0;
    for(int i=1;i<n;i++) if(b[i-1]>b[i]) return cout << "no", 0;
    cout << "yes";
    return 0;
}