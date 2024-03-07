#include <bits/stdc++.h>
using namespace std;
using ll=long long;

char A[505][505];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<string> v(n);
    for(auto &i:v) cin >> i;
    int f=1;
    for(int i=1;i<n;i++) f &= v[i][0]==v[0][0];
    cout << f;
    return 0;
}