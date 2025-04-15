#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a,A,b,B,P; cin >> A >> a >> B >> b >> P;
    if(A>P || B>P) cout << "No";
    else if(A+B<=P || a>=B || b>=A) cout << "Yes";
    else cout << "No";
    return 0;
}