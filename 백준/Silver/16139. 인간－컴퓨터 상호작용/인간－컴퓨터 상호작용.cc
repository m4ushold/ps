#include <bits/stdc++.h>
using namespace std;

int Q, A[202020][26];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    for(int i=1;i<=s.size();i++) {
        A[i][s[i-1]-'a']++;
        for(int j=0;j<26;j++) A[i][j]+=A[i-1][j];
    }
    cin >> Q;
    for(int q=0,l,r;q<Q;q++) {
        char c; cin >> c >> l >> r;
        cout << A[r+1][c-'a']-A[l][c-'a'] << '\n';
    }
    return 0;
}