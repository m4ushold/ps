#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        auto cnt = [](int a) {
            int c=0;
            for(int i=1;i<=a;i++) if(a%i==0) c++;
            return c;
        };
        int a; cin >> a;
        cout << a << ' ' << cnt(a) << '\n';
    }
    return 0;
}