#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    do {
        for(int i:v) cout << i << ' ';
        cout << '\n';
    } while(next_permutation(v.begin(),v.end()));

    return 0;
}