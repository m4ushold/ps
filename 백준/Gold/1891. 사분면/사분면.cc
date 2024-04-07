#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll D, X, Y;
string s;

ll cy(ll d, ll y)
{
    if (s[d] == '1') {s[d] = y%2 ? '4' : '1'; return y>0?(y+1)/2:y/2;}
    else if (s[d] == '2') {s[d] = y%2 ? '3' : '2'; return y>0?(y+1)/2:y/2;}
    else if (s[d] == '3') {s[d] = y%2 ? '2' : '3'; return y>0?y/2:(y-1)/2;}
    else if (s[d] == '4') {s[d] = y%2 ? '1' : '4'; return y>0?y/2:(y-1)/2;}
    return 0;
}

ll cx(ll d, ll x)
{
    if (s[d] == '1') {s[d] = x%2 ? '2' : '1'; return x>0?(x+1)/2:x/2;}
    else if (s[d] == '2') {s[d] = x%2 ? '1' : '2'; return x>0?x/2:(x-1)/2;}
    else if (s[d] == '3') {s[d] = x%2 ? '4' : '3'; return x>0?x/2:(x-1)/2;}
    else if (s[d] == '4') {s[d] = x%2 ? '3' : '4'; return x>0?(x+1)/2:x/2;}
    return 0;
}

int f(ll d, ll x, ll y)
{
    if (d < 0 && (x || y)) return false;
    if (d < 0) return true;
    return f(d-1, cx(d, x), cy(d, y));
}

int main(void)
{
    cin >> D >> s >> X >> Y;
    if (f(D-1, X, Y)) cout << s << '\n';
    else cout << "-1\n";
    return 0;
}