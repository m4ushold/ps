#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n0, n1, n2, n3, n4, i=1;
    while(cin >> n0 && n0) {
        n1=n0*3, n2=n1+1>>1, n3=3*n2, n4=n3/9;
        cout << i++ << ". " << (n1&1 ? "odd " : "even ") << n4 << "\n";
    }
    

    return 0;
}