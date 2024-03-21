#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    vector<int> v(n), a(n);
    for(int i=0;i<m;i++) a[i]=1;
    for(int &i:v) cin >> i;
    
    sort(v.begin(),v.end());
    do {
        for(int i=0;i<n;i++) if(a[i]) cout << v[i] << ' ';
        cout << '\n';
    } while(prev_permutation(a.begin(), a.end()));
    return 0;
}