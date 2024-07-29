#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int D[101010][7];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    for(int i=0;i<s.size();i++) for(int j=0;j<7;j++) D[i][j]=1e9;
    D[0][0]=0;

    for(int i=1;i<=s.size();i++) {
        char c=s[i-1];

        D[i][1] = min({D[i-1][0]+(c!='B'), D[i-1][1]+(c!='B'), D[i-1][6]+(c!='B')});
        D[i][2] = D[i-1][1]+(c!='A');
        D[i][3] = D[i-1][2]+(c!='N');
        D[i][4] = D[i-1][3]+(c!='A');
        D[i][5] = min(D[i-1][4]+(c!='N'), D[i-1][6]+(c!='N'));
        D[i][6] = D[i-1][5]+(c!='A');
    }

    cout << D[s.size()][6];
    return 0;
}