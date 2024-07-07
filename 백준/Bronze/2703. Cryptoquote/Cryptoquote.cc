#include <bits/stdc++.h>
using namespace std;

char T[202];

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    cin.ignore();
    while(t--) {
        string s, a;
        getline(cin, s), getline(cin, a);
        for(char i='A';i<='Z';i++) T[i]=a[i-'A'];
        for(char c:s) cout << (c==' ' ? c : T[c]);
        cout << '\n';
    }
    return 0;
}