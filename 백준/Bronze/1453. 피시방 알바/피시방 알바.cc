#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    set<int> s;
    for(int i=0,a;i<n;i++) cin >> a, s.insert(a);
    cout << n-s.size();
    return 0;
}