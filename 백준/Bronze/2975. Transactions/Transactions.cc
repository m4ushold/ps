#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b; char c;
    while(cin >> a >> c >> b && !(!a&&!b)) {
        if(c=='W') cout << (a-b<-200 ? "Not allowed\n" : to_string(a-b)+"\n");
        else cout << a+b << '\n';
    }
    return 0;
}