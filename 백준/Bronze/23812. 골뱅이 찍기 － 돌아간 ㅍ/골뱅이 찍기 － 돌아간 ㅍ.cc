#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++) cout << string(n,'@') << string(3*n,' ') << string(n,'@') << '\n';
    for(int i=0;i<n;i++) cout << string(n*5,'@') << '\n';
    for(int i=0;i<n;i++) cout << string(n,'@') << string(3*n,' ') << string(n,'@') << '\n';
    for(int i=0;i<n;i++) cout << string(n*5,'@') << '\n';
    for(int i=0;i<n;i++) cout << string(n,'@') << string(3*n,' ') << string(n,'@') << '\n';
    return 0;
}