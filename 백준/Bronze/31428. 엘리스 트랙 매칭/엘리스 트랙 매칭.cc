#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, cnt=0; cin >> n;
    vector<char> v(n);
    for(char &i:v) cin >> i;
    char c; cin >> c;
    for(char i:v) cnt+=i==c;
    cout << cnt;
    return 0;
}