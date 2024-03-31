#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c;
    while( cin >> a >> b >> c && (a|b)) {
        if(a+c==2*b) cout << "AP " << c+b-a << '\n';
        else cout << "GP " << c*b/a << '\n';
    }
    return 0;
}