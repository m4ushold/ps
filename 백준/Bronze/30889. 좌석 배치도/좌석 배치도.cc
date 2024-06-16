#include <bits/stdc++.h>
using namespace std;

char A[22][22];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    memset(A,'.',sizeof A);
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        string s; cin >> s;
        A[s[0]-'A'][stoi(s.substr(1))-1]='o';
    }
    for(int i=0;i<10;i++) {
        for(int j=0;j<20;j++) cout << A[i][j];
        cout << "\n";
    }
    return 0;
}