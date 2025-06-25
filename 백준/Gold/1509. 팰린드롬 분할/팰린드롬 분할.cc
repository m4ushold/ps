#include <bits/stdc++.h>
using namespace std;

int A[2525][2525], D[2525];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size();
    s = "#" + s;
    for(int i=2;i<=n;i++) if(s[i-1] == s[i]) A[i-1][i]=1;
    for(int i=1;i<=n;i++) A[i][i]=1;

    for(int l=3;l<=n;l++) {
        for(int i=1,j=i+l-1;j<=n;i++,j++) {
            if(A[i+1][j-1] && s[i] == s[j]) A[i][j] = 1; 
        }
    }
    for(int i=1;i<=n;i++) {
        D[i] = D[i-1] + 1;
        for(int l=1;l<=i;l++) {
            if(A[i-l+1][i]) D[i] = min(D[i], D[i-l]+1);
        }
    }
    cout << D[n];
    return 0;
}