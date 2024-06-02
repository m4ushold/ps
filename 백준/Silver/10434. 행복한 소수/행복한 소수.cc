#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int S[10101]={1,1};

int g(int x) {
    int r=0;
    for(char c:to_string(x)) r+=(c-'0')*(c-'0');
    return r;
}

bool f(int i) {
    set<int> s;
    while(s.insert(i).second) i=g(i);
    return i==1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=2;i*i<10101;i++) if(!S[i]) for(int j=2*i;j<10101;j+=i) S[j]=1;
    int t; cin >> t;
    while(t--) {
        int n, a; cin >> n >> a;
        cout << n << ' ' << a << ' ' << (!S[a] && f(a) ? "YES\n" : "NO\n");
    }
    return 0;
}