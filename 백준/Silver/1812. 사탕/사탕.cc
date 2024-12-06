#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    int s=0, f=1;
    for(int &i:v) cin >> i, s+=f*i, f*=-1;
    cout << (s/=2) << '\n';
    for(int i=0;i<n-1;i++) cout << (s=v[i]-s) << '\n';
    return 0;
}