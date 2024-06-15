#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,o=0,e=0; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i, i&1?o++:e++;
    cout << (n&1?e+1==o:e==o);
    return 0;
}