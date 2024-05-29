#include <bits/stdc++.h>
using namespace std;

int S[10000] = {1,1,};
vector<int> p;

bool isPrime(int n)
{
    for(int i=0;p[i]*p[i]<=n;i++) if (n%p[i]==0) return false;
    return true;
}

bool isPal(string s)
{
    for(int i=0;i<s.length()/2;i++) if (s[i] != s[s.length()-i-1]) return false;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=2;i<10000;i++) if (!S[i]) {p.push_back(i); for(int j=2*i;j<=10000;j+=i) S[j] = 1;}

    int a, b;
    cin >> a >> b;
    for(int i=a;i<=min(b, 9989899);i++) {
        if (isPrime(i) && isPal(to_string(i))) cout << i << '\n';
    }

    cout << "-1\n";
    return 0;
}