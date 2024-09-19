#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const string a1 = "Messi", a2 = "Messi Gimossi";
ll a[64], M, N=64;

ll f(ll n, ll m)
{
    if (n == 1) return a1[m-1];
    if (n == 2) return a2[m-1];

    if (m == a[n-1] + 1) return ' ';
    else if (m <= a[n-1]) return f(n-1, m);
    else return f(n-2, m-a[n-1]-1);
}

int main(void)
{
    cin >> M;

    a[1] = a1.length(); a[2] = a2.length();
    for(int i=3; i < N;i++) a[i] = a[i-1] + a[i-2] + 1;

    ll res = f(N, M);
    if (res == ' ') cout << "Messi Messi Gimossi\n";
    else cout << (char)res << '\n';
    return 0;
}