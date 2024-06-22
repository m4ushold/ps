#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> a(3), b(3);
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        for(int &j:a) cin >> j;
        for(int &j:b) cin >> j;
        sort(a.begin(),a.end()), sort(b.begin(),b.end());
        if(a[0]!=b[0] || a[1]!=b[1] || a[2]!=b[2]) {cout << "NO\n"; continue;}
        cout << (a[0]*a[0]+a[1]*a[1]==a[2]*a[2] ? "YES\n" : "NO\n");
    }
    return 0;
}