#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c=0; cin >> a >> b;
    set<int> s;
    for(int i=0,j;i<a;i++) cin >> j, s.insert(j);
    for(int i=0,j;i<b;i++) cin >> j, c+=!s.insert(j).second;
    cout << a+b-2*c << '\n';
    return 0;
}