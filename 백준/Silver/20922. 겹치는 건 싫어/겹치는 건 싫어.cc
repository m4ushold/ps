#include <bits/stdc++.h>
using namespace std;

int C[101010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    int mx=0;
    for(int i=0,j=0;j<n;j++) {
        C[v[j]]++;
        while(C[v[j]]>k && i<j) C[v[i]]--, i++;
        mx=max(mx,j-i+1);
    }
    cout << mx;
    return 0;
}