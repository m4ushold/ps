#include <bits/stdc++.h>
#define c 299792458.0
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    double a,b; cin >> a >> b;
    cout << fixed << setprecision(12) << (a+b)/(1+(a*b)/(c*c));
    return 0;
}