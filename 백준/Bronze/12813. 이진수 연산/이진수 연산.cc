#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    bitset<100'000> a,b; cin >> a >> b;
    cout << (a&b) << '\n' << (a|b) << '\n' << (a^b) << '\n' << ~a << '\n' << ~b;
    return 0;
}