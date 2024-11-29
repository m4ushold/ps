#include <bits/stdc++.h>
using namespace std;

int A[11];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        string a,b; cin >> a >> b;
        if(b[0]=='h') for(int i=n;i<11;i++) A[i]=1;
        else if(b[0]=='l') for(int i=n;i;i--) A[i]=1;
        else {
            cout << "Stan " << (A[n] ? "is dis" : "may be ") << "honest\n";
            memset(A, 0, sizeof(A));
        }
    }
    return 0;
}