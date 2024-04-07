#include <bits/stdc++.h>
using namespace std;
using ll=long long;

char A[101][101];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n=sqrt(s.size());
        for(int i=0;i<s.size();i++) A[i/n][i%n] = s[i];
        for(int j=n-1;j>=0;j--) for(int i=0;i<n;i++) cout << A[i][j];
        cout << '\n';
    }
    return 0;
}