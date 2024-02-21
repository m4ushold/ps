#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        vector<int> a(n), b(m);
        for(int &i:a) cin >> i;
        for(int &i:b) cin >> i;

        sort(a.begin(),a.end()), sort(b.begin(), b.end());
        int l=0,r=0;
        while(l<n && r<m) a[l]<b[r]?++l:++r;
        
        cout << (r==m ? "S\n" : "B\n");
    }
    return 0;
}