#include <bits/stdc++.h>
using namespace std;

map<char,int> A[55];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int k; cin >> k;
    int n=s.size();
    if(n==k) return cout << 0, 0;
    for(int i=0;i<n;i++) {
        A[i%(n-k)][s[i]]++;
    }
    int cnt=0;
    for(int i=0;i<n-k;i++) {
        int sum=0, mx=0;
        for(auto [j,k]:A[i]) sum+=k, mx=max(mx,k);
        cnt+=sum-mx;
    }
    cout << cnt;
    return 0;
}